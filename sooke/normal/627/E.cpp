#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 3e3 + 5;

int r, c, n, k, cnt[N], pre[N], nxt[N], f[N], g[N];
long long ans, now;

struct Point {
    int x, y;
} a[N];

bool operator <(const Point &u, const Point &v) {
    return u.x == v.x ? u.y < v.y : u.x < v.x;
}

int main() {
    r = read(); c = read(); n = read(); k = read();
    for (int i = 0; i < n; i++) {
        a[i].x = read(); a[i].y = read();
    }
    std::sort(a, a + n);
    cnt[0] = cnt[c + 1] = 1e9;
    for (int xl = 1; xl <= r; xl++) {
        int l = 0, lst = 0;
        for (; l < n && a[l].x < xl; l++);
        for (int i = l; i < n; i++) { cnt[a[i].y]++; }
        f[0] = 0; g[0] = cnt[0]; now = 0;
        for (int y = 1; y <= c + 1; y++) {
            if (cnt[y] == 0) { continue; }
            nxt[lst] = y; pre[y] = lst; 
            now += f[lst] * (y - lst);
            f[y] = f[lst]; g[y] = g[lst] + cnt[y];
            for (; g[y] - cnt[f[y]] >= k; g[y] -= cnt[f[y]], f[y] = nxt[f[y]]);
            lst = y;
        }
        for (int xr = r, i = n - 1; xr >= xl; xr--) {
            ans += now;
            for (; i >= l && a[i].x == xr; i--) {
                cnt[a[i].y]--;
                for (int y = a[i].y; y <= c + 1; y = nxt[y]) {
                    if (f[y] > a[i].y) { break; }
                    now -= f[y] * (nxt[y] - y); g[y]--;
                    for (; g[y] < k; f[y] = pre[f[y]], g[y] += cnt[f[y]]);
                    now += f[y] * (nxt[y] - y);
                }
                int y = a[i].y;
                if (cnt[y] == 0) { nxt[pre[y]] = nxt[y]; pre[nxt[y]] = pre[y]; }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}