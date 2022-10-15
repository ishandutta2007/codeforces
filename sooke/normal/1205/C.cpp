#include <bits/stdc++.h>

int query(int x, int y, int r, int c) {
    std::cout << "? " << x + 1 << " " << y + 1 << " " << r + 1 << " " << c + 1 << std::endl;
    int res; std::cin >> res; return res;
}

const int N = 105;

int n;
char f[N][N];

std::vector<int> ex[N][N], ey[N][N], ew[N][N];

int link(int x, int y, int r, int c, int w) {
    ex[x][y].push_back(r); ey[x][y].push_back(c); ew[x][y].push_back(w);
    ex[r][c].push_back(x); ey[r][c].push_back(y); ew[r][c].push_back(w);
}

void dfs(int x, int y, char c) {
    if (f[x][y] != '?') { return; } f[x][y] = c;
    for (int i = 0; i < ex[x][y].size(); i++) {
        dfs(ex[x][y][i], ey[x][y][i], c ^ ew[x][y][i]);
    }
}

void fill(char c, char d) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f[i][j] == c) { f[i][j] = d; }
            if (f[i][j] == (c ^ 1)) { f[i][j] = d ^ 1; }
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                if (i - 1 >= 0 && j + 1 < n && (f[i][j] ^ 1) == f[i - 1][j + 1]) {
                    if (j + 2 < n) {
                        fill(f[i - 1][j], f[i][j + 2] ^ query(i - 1, j, i, j + 2) ^ 1);
                    } else {
                        fill(f[i - 1][j], f[i + 1][j + 1] ^ query(i - 1, j, i + 1, j + 1) ^ 1);
                    }
                    return;
                }
            } else {
                if (i - 1 >= 0 && j + 1 < n && (f[i][j] ^ 1) == f[i - 1][j + 1]) {
                    if (j + 2 < n) {
                        fill(f[i][j + 2], f[i - 1][j] ^ query(i - 1, j, i, j + 2) ^ 1);
                    } else if (i + 1 < n && j + 1 < n) {
                        fill(f[i + 1][j + 1], f[i - 1][j] ^ query(i - 1, j, i + 1, j + 1) ^ 1);
                    } else if (i - 2 >= 0) {
                        fill(f[i - 2][j], f[i][j + 1] ^ query(i - 2, j, i, j + 1) ^ 1);
                    } else {
                        fill(f[i - 1][j - 1], f[i][j + 1] ^ query(i - 1, j - 1, i, j + 1) ^ 1);
                    }
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                if (i + 2 < n && j + 2 < n) {
                    if (f[i][j] == '1' && f[i + 1][j + 1] == '1' && f[i + 2][j + 2] == '0') {
                        if (query(i + 1, j, i + 2, j + 2) || query(i, j, i + 2, j + 1)) {
                            fill(f[i + 2][j + 1], '1');
                        } else {
                            fill(f[i + 2][j + 1], '0');
                        }
                        return;
                    }
                    if (f[i][j] == '1' && f[i + 1][j + 1] == '0' && f[i + 2][j + 2] == '0') {
                        if (query(i + 1, j, i + 2, j + 2) || query(i, j, i + 2, j + 1)) {
                            fill(f[i + 1][j], '0');
                        } else {
                            fill(f[i + 1][j], '1');
                        }
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { f[i][j] = '?'; }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                if (i == 0 && j == 0) {
                    f[i][j] = '1'; continue;
                }
                if (i == n - 1 && j == n - 1) {
                    f[i][j] = '0'; continue;
                }
                if (i == 0) {
                    f[i][j] = query(i, j - 2, i, j) ? f[i][j - 2] : (f[i][j - 2] ^ 1); continue;
                }
                if (j == 0) {
                    f[i][j] = query(i - 2, j, i, j) ? f[i - 2][j] : (f[i - 2][j] ^ 1); continue;
                }
                f[i][j] = query(i - 1, j - 1, i, j) ? f[i - 1][j - 1] : (f[i - 1][j - 1] ^ 1); continue;
            } else {
                if (i == 1 && j == 0) { continue; }
                if (i == 0 && j == 1) {
                    link(i, j, i + 1, j + 1, query(i, j, i + 1, j + 1) ^ 1); continue;
                }
                if (j >= 2) {
                    link(i, j - 2, i, j, query(i, j - 2, i, j) ^ 1); continue;
                }
                if (i >= 2) {
                    link(i - 2, j, i, j, query(i - 2, j, i, j) ^ 1); continue;
                }
            }
        }
    } dfs(0, 1, '2');
    solve();
    std::cout << "!" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << f[i][j];
        } std::cout << std::endl;
    }
    return 0;
}