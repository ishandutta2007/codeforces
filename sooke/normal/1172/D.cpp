#include <cstdio>
#include <algorithm>

const int N = 1005;

int n, m, a[N], b[N], r[N], c[N], pa[N], pb[N], pr[N], pc[N], sx[N], sy[N], tx[N], ty[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) { scanf("%d", &pr[i]); }
    for (int i = 1; i <= n; i++) { scanf("%d", &pc[i]); }
    for (int i = 1; i <= n; i++) { a[i] = b[i] = pa[i] = pb[i] = r[pr[i]] = c[pc[i]] = i; }
    for (int i = 1; i <= n; i++) {
        if (a[i] != r[i] || b[i] != c[i]) {
            m++; sx[m] = ty[m] = i; tx[m] = pa[r[i]]; sy[m] = pb[c[i]];
            std::swap(a[i], a[tx[m]]); pa[a[i]] = a[i]; pa[a[tx[m]]] = tx[m];
            std::swap(b[i], b[sy[m]]); pb[b[i]] = b[i]; pb[b[sy[m]]] = sy[m];
        }
    }
    printf("%u\n", m);
    for (int i = 1; i <= m; i++) { printf("%d %d %d %d\n", sx[i], sy[i], tx[i], ty[i]); }
    return 0;
}