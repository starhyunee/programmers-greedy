#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

/* ÇÁ·Î±×·¡¸Ó½º °íµæÁ¡ kit - Å½¿å¹ý - Ã¼À°º¹ */
int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n + 2, 1);
    student[0] = 0;
    student[n + 1] = 0;
    int answer = 0;

    for (int i = 0; i < lost.size(); i++) {
        student[lost[i]]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        student[reserve[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!student[i]) {
            if (student[i - 1] == 2) {
                student[i - 1] = 1;
                student[i] = 1;
            }
            else if (student[i + 1] == 2) {
                student[i + 1] = 1;
                student[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (student[i])
            answer++;
    }

    return answer;
}

/* ÇÁ·Î±×·¡¸Ó½º °íµæÁ¡ kit - Å½¿å¹ý - Å« ¼ö ¸¸µé±â */
string solution(string number, int k) {
    while (k) {
        for (int i = 0; i < number.length(); i++) {
            if (i == number.length() - 1 || number[i] < number[i + 1]) {
                number.erase(i, 1);
                k--;
                break;
            }
        }
    }

    return number;
}

/* ÇÁ·Î±×·¡¸Ó½º °íµæÁ¡ kit - Å½¿å¹ý - ±¸¸íº¸Æ® */
int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();
    sort(people.begin(), people.end(), greater<int>());

    int first = 0;
    int second = size - 1;
    while (first <= second) {
        if (people[first] <= limit / 2) {
            answer += (second - first) / 2;
            first++;
            answer++;
            break;
        }
        if (people[first] + people[second] <= limit) {
            first++;
            second--;
            answer++;
        }
        else {
            first++;
            answer++;
        }
    }
    return answer;
}


/* ÇÁ·Î±×·¡¸Ó½º °íµæÁ¡ kit - Å½¿å¹ý - ¼¶ ¿¬°áÇÏ±â */
int Parent[101];

int getParent(int parent[], int x) {
    if (parent[x] == x)
        return x;
    return getParent(parent, parent[x]);
}
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
int ifsameParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        return 1;
    return 0;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int, pair<int, int>>> vec;
    for (int i = 0; i < costs.size(); i++) {
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
        vec.push_back({ cost,{start,end} });
    }
    for (int i = 0; i < n; i++) {
        Parent[i] = i;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        int start = vec[i].second.first;
        int end = vec[i].second.second;
        int cost = vec[i].first;
        if (!ifsameParent(Parent, start, end)) {
            answer = answer + cost;
            unionParent(Parent, start, end);
        }
    }

    return answer;
}


/* ÇÁ·Î±×·¡¸Ó½º °íµæÁ¡ kit - Å½¿å¹ý - ´Ü¼Ó Ä«¸Þ¶ó */
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    int camera = -341424;
    for (int i = 0; i < routes.size(); i++) {
        if (camera < routes[i][0]) {
            answer++;
            camera = routes[i][1];
        }
        if (camera >= routes[i][1])
            camera = routes[i][1];
    }
    return answer;
}