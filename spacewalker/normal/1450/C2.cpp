#include <bits/stdc++.h>

using namespace std;

char grid[400][400];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
        vector<pair<int, int>> putangina[3];
        for (int i = 0; i < 3; ++i) putangina[i] = vector<pair<int, int>>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '.') putangina[(i + j + (grid[i][j] == 'O')) % 3].emplace_back(i, j);
            }
        }
        int k = 0; 
        for (int i = 1; i < 3; ++i) if (putangina[i].size() < putangina[k].size()) k = i;
        for (auto [i, j] : putangina[k]) grid[i][j] = (grid[i][j] == 'O' ? 'X' : 'O');
        for (int i = 0; i < n; ++i) printf("%s\n", grid[i]);
    }
    return 0;
}