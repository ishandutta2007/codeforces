#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 200;

char grid[NMAX][NMAX];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    vector<pair<int, int>> yeets;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = 'S';
            if ((i + j) % 2 == 0) yeets.emplace_back(i, j);
        }
    }
    if (k > yeets.size()) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < k; ++i) {
            grid[yeets[i].first][yeets[i].second] = 'L';
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%c", grid[i][j]);
            }
                printf("\n");
        }
    }
    return 0;
}