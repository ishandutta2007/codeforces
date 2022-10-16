// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1005;

int n, m, q, a[N][N];

LL ans;

bool inline chk(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m || a[x][y]) return 0;
    return 1;
}

int inline get(int x, int y, int dx, int dy, int ox, int oy) {
    int c = 0;
    while (1) {
        x += dx, y += dy;
        if (!chk(x, y)) return c;
        c++;
        x += ox, y += oy;
        if (!chk(x, y)) return c;
        c++;
    }
}

int main() {
    read(n), read(m), read(q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = min(n - i + 1, m - j + 1);
            ans += 2 * (2 * x - 1) - 1;
            if (n - i + 1 != m - j + 1) ans++;
        }
    }
    while (q--) {
        int x, y; read(x), read(y);
        int A = get(x, y, -1, 0, 0, -1);
        int B = get(x, y, 0, 1, 1, 0);
        int C = get(x, y, 0, -1, -1, 0);
        int D = get(x, y, 1, 0, 0, 1);
        LL gx = (A + 1) * (B + 1) + (C + 1) * (D + 1) - 1;
        if (!a[x][y]) ans -= gx;
        else ans += gx; 
        printf("%lld\n", ans);
        a[x][y] ^= 1;
    }
    return 0;
}