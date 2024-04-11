#include <bits/stdc++.h>

using namespace std;

char strng[500];
char ans[500];
bool solve() {
    scanf("%s", strng);
    vector<vector<int>> graph(26);
    vector<vector<bool>> isLinked(26, vector<bool>(26));
    int n = strlen(strng);
    for (int i = 0; i + 1 < n; ++i) {
        int a = strng[i] - 'a', b = strng[i+1] - 'a';
        isLinked[a][b] = isLinked[b][a] = true;
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (isLinked[i][j]) graph[i].push_back(j);
        }
    }
    vector<int> attAnswer;
    vector<bool> vis(26);
    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (!vis[i] && graph[i].size() == 1) {
//            printf("STARTING WITH %d\n", i);
            q.push(i);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
//                printf("visit %d\n", cur);
                vis[cur] = true;
                attAnswer.push_back(cur);
                for (int nxt : graph[cur]) {
//                    printf("push %d\n", nxt);
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        } else if (graph[i].size() == 0) attAnswer.push_back(i);
    }
    if (attAnswer.size() < 26) return false;
    else {
        vector<int> placeInAns(26);
        for (int i = 0; i < 26; ++i) placeInAns[attAnswer[i]] = i;
        for (int i = 0; i + 1 < n; ++i) {
            if (abs(placeInAns[strng[i] - 'a'] - placeInAns[strng[i+1] - 'a']) > 1) return false;
        }
        for (int i = 0; i < 26; ++i) {
            ans[i] = (char)(attAnswer[i] + 'a');
        }
        return true;
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        if (solve()) {
            printf("YES\n");
            printf("%s\n", ans);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}