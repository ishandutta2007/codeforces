#include <bits/stdc++.h>

inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e5 + 5, M = 505;

int n, m, num, ans = 1e9, p[N], cnt[N], e[M][M], dis[M][M];
long long a[N];

int solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] >> j & 1) {
                cnt[j]++;
                if (cnt[j] == 3) { return 3; }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) { p[num++] = i; }
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            e[i][j] = dis[i][j] = 1e6;
        }
    }
    for (int i = 0; i < num; i++) {
        e[i][i] = dis[i][i] = 0;
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i != j && ((a[p[i]] & a[p[j]]) != 0)) {
                e[i][j] = dis[i][j] = 1;
            }
        }
    }
    for (int k = 0; k < num; k++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < i; j++) {
                ans = std::min(ans, dis[i][j] + e[i][k] + e[k][j]);
            }
        }
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    return ans >= 1e5 ? -1 : ans;
}

int main() {
    n = read(); m = 63;
    for (int i = 0; i < n; i++) { a[i] = read(); }
    printf("%d\n", solve());
    return 0;
}