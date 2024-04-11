#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; scanf("%d %d", &n, &m);
    vector<multiset<int>> paths(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; scanf("%d", &x);
            paths[i].insert(x);
        }
    }
    vector<vector<int>> runnerPaths(m, vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
        int minIndex = -1;
        for (int j = 0; j < n; ++j) {
            if (minIndex == -1 || *paths[j].begin() < *paths[minIndex].begin()) minIndex = j;
        }
        for (int j = 0; j < n; ++j) {
            if (j == minIndex) runnerPaths[i][j] = *paths[j].begin();
            else runnerPaths[i][j] = *paths[j].rbegin();
        }
        for (int j = 0; j < n; ++j) paths[j].erase(paths[j].find(runnerPaths[i][j]));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) printf("%d ", runnerPaths[j][i]);
        printf("\n");
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}