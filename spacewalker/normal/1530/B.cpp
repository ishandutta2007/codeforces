#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 21;

void solve() {
    int h, w; scanf("%d %d", &h, &w);
    static char grid[NMAX][NMAX];
    memset(grid, 0, sizeof grid);
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) grid[i][j] = '0';
    grid[0][0] = grid[h-1][0] = grid[0][w-1] = grid[h-1][w-1] = '1';
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '1') continue;
            if (i == 0 || i == h - 1) {
                if (j % 2 == 0 && j + 1 < w - 1) grid[i][j] = '1';
            } 
            if (j == 0 || j == w - 1) {
                if (i % 2 == 0 && i + 1 < h - 1) grid[i][j] = '1';
            }
        }
    }
    for (int i = 0; i < h; ++i) printf("%s\n", grid[i]);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}