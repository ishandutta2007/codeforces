#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 510;

char grid[NMAX][NMAX];
void solve() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
    bool shiftIt = false;
    if (n % 3 == 0) {
        printf("%s\n", grid[0]);
        shiftIt = true;
    }
    for (int i = shiftIt ? 1 : 0; i < n; i += 3) {
        for (int j = 0; j < m; ++j) printf("X");
        printf("\n");
        if (i == n - 1) break;
        if (i + 3 < n) {
            int itp = 0;
            for (int j = 0; j < m; ++j) if (grid[i+1][j] == 'X' || grid[i+2][j] == 'X') itp = j;
            grid[i+1][itp] = grid[i+2][itp] = 'X';
            printf("%s\n%s\n", grid[i+1], grid[i+2]);
        } else {
           printf("%s\n", grid[i+1]); 
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}