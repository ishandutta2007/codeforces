#include <bits/stdc++.h>
using namespace std;

#define N 250250
int n, m, fac[N];

int main() {
    scanf("%d %d", &n, &m);
    fac[0] = 1;
    for (int i = 1; i <= n; i ++) fac[i] = 1ll * i * fac[i-1] % m;
    int ans = 0;
    for (int k = 0; k < n; k ++) {
        int c = 1ll * fac[k+1] * fac[n-k] % m;
        ans = (ans + 1ll * c * (n - k)) % m;
    }
    printf("%d\n", ans);

    return 0;
}