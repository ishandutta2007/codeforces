#include <cstdio>
#include <algorithm>

const int N = 200005;

int n, a[N];
long long ans, f[N];

struct FenwickTree {
    int f[N];

    inline void modify(int u) {
        for (int i = u; i <= n; i += i & -i) {
            if (a[f[i]] < a[u]) { f[i] = u; }
        }
    }
    inline int query(int u) {
        int res = 0;
        for (int i = u; i; i ^= i & -i) {
            if (a[res] < a[f[i]]) { res = f[i]; }
        }
        return res;
    }
} fwt;

int main() {
    scanf("%d", &n); a[n] = n;
    for (int i = 1; i < n; i++) { scanf("%d", &a[i]); }
    for (int i = n, j; i; i--) {
        if (a[i] == n) { f[i] = n - i; } else {
            j = fwt.query(a[i]);
            f[i] = f[j] - (a[i] - j) + n - i;
        }
        ans += f[i]; fwt.modify(i);
    }
    printf("%lld\n", ans);
    return 0;
}