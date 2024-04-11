#include <bits/stdc++.h>

const int N = 3e3 + 5;

int n, m, _r, _c, _w, _a, _b, _p, a[N][N], b[N][N];
int l, r, que[N];
long long ans;

int main() {
    std::cin >> n >> m >> _r >> _c >> _w >> _a >> _b >> _p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = _w; _w = (1ll * _a * _w + _b) % _p;
        }
    }
    for (int i = 0; i < n; i++) {
        l = 1; r = 0;
        for (int j = 0; j < m; j++) {
            for (; l <= r && que[l] + _c <= j; l++);
            for (; l <= r && a[i][que[r]] >= a[i][j]; r--);
            que[++r] = j; b[i][j] = a[i][que[l]];
        }
    }
    for (int j = 0; j < m; j++) {
        l = 1; r = 0;
        for (int i = 0; i < n; i++) {
            for (; l <= r && que[l] + _r <= i; l++);
            for (; l <= r && b[que[r]][j] >= b[i][j]; r--);
            que[++r] = i;
            if (i >= _r - 1 && j >= _c - 1) { ans += b[que[l]][j]; }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}