#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 1000500;
const int mod = 1e9 + 7;

int n, f[N], s[N], b[N], ib[N];

int main() {

    b[0] = 1;
    ib[0] = 1;
    for(int i = 1; i < N; i ++) {
        b[i] = b[i - 1] << 1;
        if(b[i] >= mod) b[i] -= mod;
        ib[i] = 1ll * ib[i - 1] * (mod + 1 >> 1) % mod;
    }

    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d", &n);
        f[n] = 1;
        s[n + 1] = 0;
        s[n] = 1;
        for(int k = n - 1; k; k --) {
            f[k] = s[k + 1] - s[min(n + 1, k << 1)];
            if(f[k] < 0) f[k] += mod;
            s[k] = s[k + 1] + f[k];
            if(s[k] >= mod) s[k] -= mod;
        }
        for(int i = 1; i <= n; i ++) {
            f[i] <<= 1;
            if(f[i] >= mod) f[i] -= mod;
        }
        for(int i = 1; i <= n; i ++) {
            f[i] = 1ll * f[i] * b[i >> 1] % mod * ib[n] % mod;
            printf("%d\n", f[i]);
        }
    }

    return 0;
}