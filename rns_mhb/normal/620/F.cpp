#include <bits/stdc++.h>
using namespace std;

#define N 50005
#define Q 5005

int n, q;
int z[20*N];
int g[N], a[N], b[N];
int l[Q], r[Q], ans[Q];

int main() {
    scanf("%d %d", &n, &q);
    z[0] = 0;
    for (int i = 1; i < 20*N; i ++) z[i] = z[i-1] ^ i;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        g[i] = z[a[i]];
    }
    for (int i = 0; i < q; i ++) scanf("%d %d", &l[i], &r[i]);
    for (int i = 1; i <= n; i ++) {
        int mx = 0;
        for (int j = i; j <= n; j ++) {
            int cur = g[i] ^ g[j] ^ (a[i] < a[j] ? a[i] : a[j]);
            if (mx < cur) mx = cur;
            b[j] = mx;
        }
        for (int j = 0; j < q; j ++) {
            if (l[j] <= i && i <= r[j]) {
                if (ans[j] < b[r[j]]) ans[j] = b[r[j]];
            }
        }
    }
    for (int i = 0; i < q; i ++) printf("%d\n", ans[i]);
}