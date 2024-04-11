#include <bits/stdc++.h>

inline char read() {
    char c; for (c = getchar(); c != '.' && c != 'X'; c = getchar()); return c;
}

int n, m, ans;
std::vector<std::vector<int>> s;
std::vector<std::vector<char>> a;
std::vector<std::vector<long long>> f;

bool check(int i, int j, int x, int y) {
    if (i < 1 || j < 1 || x > n || y > m) { return false; }
    i--; j--;
    return 1ll * (x - i) * (y - j) == s[x][y] - s[x][j] - s[i][y] + s[i][j];
}
void cover(int i, int j, int x, int y) {
    x++; y++;
    f[i][j]++; f[i][y]--; f[x][j]--; f[x][y]++;
}

bool check(int mid) {
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            f[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'X' && check(i - mid, j - mid, i + mid, j + mid)) {
                cover(i - mid, j - mid, i + mid, j + mid);
            }
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            f[i][j] = f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.' && f[i][j] > 0) { return false; }
            if (a[i][j] == 'X' && f[i][j] == 0) { return false; }
        }
    }
    return true;
}
void solve(int mid) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'X') {
                if (check(i - mid, j - mid, i + mid, j + mid)) {
                    a[i][j] = 'X';
                } else {
                    a[i][j] = '.';
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    a.resize(n + 1); f.resize(n + 2); s.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        a[i].resize(m + 1); f[i].resize(m + 2); s[i].resize(m + 1);
    }
    f[n + 1].resize(m + 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = read();
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (int) (a[i][j] == 'X');
        }
    }
    for (int l = 0, r = 1e6, mid; l <= r; ) {
        mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1; ans = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", ans); solve(ans);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            putchar(a[i][j]);
        }
        printf("\n");
    }
    return 0;
}