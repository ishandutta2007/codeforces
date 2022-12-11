#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

void solve() {
    int n; scanf("%d", &n);
    vector<vector<int>> arrs(2 * n, vector<int>(n));
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < n; ++j) scanf("%d", &arrs[i][j]);
        for (int j = 0; j < n; ++j) --arrs[i][j];
    }
    // 0 = unsure, 1 = sure in latin square, -1 = sure NOT in latin square
    vector<int> status(2 * n, 0); 
    vector<vector<int>> colCounts(n, vector<int>(n)); // count in column j
    auto removeRowFrom = [&] (int i, int newStatus) {
//        printf("removing row %d %d\n", i, newStatus);
        if (status[i] != 0) return;
        status[i] = newStatus;
        for (int j = 0; j < n; ++j) --colCounts[j][arrs[i][j]];
    };
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < n; ++j) ++colCounts[j][arrs[i][j]];
    }
    while (true) {
        int sureInLS = -1;
        for (int i = 0; i < 2 * n; ++i) {
            if (status[i] != 0) continue;
            for (int j = 0; j < n; ++j) if (colCounts[j][arrs[i][j]] == 1) sureInLS = i;
        }
        if (sureInLS == -1) break;
        removeRowFrom(sureInLS, 1);
        for (int i = 0; i < 2 * n; ++i) {
            if (status[i] != 0) continue;
            bool sharesElem = false;
            for (int j = 0; j < n; ++j) if (arrs[sureInLS][j] == arrs[i][j]) {
                sharesElem = true;
                break;
            }
            if (sharesElem) removeRowFrom(i, -1);
        }
    }
    vector<vector<int>> graph(2 * n);
    for (int j = 0; j < n; ++j) {
        vector<vector<int>> toPair(n);
        for (int i = 0; i < 2 * n; ++i) {
            if (status[i] != 0) continue;
            toPair[arrs[i][j]].push_back(i);
        }
        for (int v = 0; v < n; ++v) {
            if (!toPair[v].empty()) {
                graph[toPair[v][0]].push_back(toPair[v][1]);
                graph[toPair[v][1]].push_back(toPair[v][0]);
            }
        }
    }
    ll countAns = 1;
    vector<int> color(2 * n); // -1 or 1 or 0
    for (int i = 0; i < 2 * n; ++i) {
        if (status[i] != 0 || color[i] != 0) continue;
        queue<int> q;
        color[i] = 1;
        q.push(i);
        countAns = (2 * countAns) % MOD;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : graph[cur]) {
                if (color[nxt] != 0) continue;
                color[nxt] = color[cur] * -1;
                q.push(nxt);
            }
        }
    }
    vector<int> construction;
    for (int i = 0; i < 2 * n; ++i) {
        if (status[i] == 1 || color[i] == 1) construction.push_back(i);
    }
    printf("%lld\n", countAns);
    for (int v : construction) printf("%d ", v + 1);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}