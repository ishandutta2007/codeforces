#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) scanf("%d", &grid[i][j]);
    }
    vector<set<int>> stopPoints(m);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) if (grid[i][j] != 2) stopPoints[j].insert(i);
        stopPoints[j].insert(n);
    }
    while (k--) {
        int startc; scanf("%d", &startc); --startc;
        int ccol = startc;
        int crow = 0;
        while (crow < n) {
            crow = *stopPoints[ccol].lower_bound(crow);
            // printf("stopping at %d %d\n", crow, ccol);
            if (crow < n) {
                // printf("cell %d\n", grid[crow][ccol]);
                int oldCell = grid[crow][ccol];
                grid[crow][ccol] = 2;
                stopPoints[ccol].erase(crow);
                if (oldCell == 1) ++ccol;
                else if (oldCell == 3) --ccol;
            }
            // printf("moved to %d %d\n", crow, ccol);
        }
        printf("%d ", ccol + 1);
    }
    printf("\n");
}