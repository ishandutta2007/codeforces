#include <cctype>
#include <cstdio>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, k, bl, br, a[N], cnt[N];
long long now, f[N], g[N];

inline int insert(int x) {
    now += cnt[x]++;
}
inline int remove(int x) {
    now -= --cnt[x];
}

long long calc(int l, int r) {
    while (l < bl) { insert(a[--bl]); }
    while (br < r) { insert(a[++br]); }
    while (bl < l) { remove(a[bl++]); }
    while (r < br) { remove(a[br--]); }
    return now;
}

void solve(int l, int r, int sl, int sr) {
    if (l > r) { return; }
    int mid = l + r >> 1, s = sl;
    for (int i = sl; i <= sr && i <= mid; i++) {
        if (f[mid] > g[i - 1] + calc(i, mid)) {
            f[mid] = g[i - 1] + calc(i, mid); s = i;
        }
    }
    solve(l, mid - 1, sl, s);
    solve(mid + 1, r, s, sr);
}

int main() {
    n = read(); k = read(); bl = 1;
    for (int i = 1; i <= n; i++) { a[i] = read(); f[i] = 1e18; }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) { g[j] = f[j]; f[j] = 1e18; }
        solve(1, n, 1, n);
    }
    printf("%I64d\n", f[n]);
    return 0;
}