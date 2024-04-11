#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2 == 0) grid[i][j] = 720720;
            else grid[i][j] = 720720 + grid[i][j] * grid[i][j] * grid[i][j] * grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) printf("%d ", grid[i][j]);
        printf("\n");
    }

}