#include<bits/stdc++.h>
using namespace std;

#define inf 1000000000000000ll

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n, k;
        scanf("%d%d", &n, &k);
        int l, r, L, R;
        scanf("%d%d%d%d", &l, &r, &L, &R);
        if(l > L) swap(l, L), swap(r, R);
        int c = max(0, min(r, R) - max(L, l));
        if(1ll * c * n >= k) {
            puts("0");
            continue;
        }
        k -= c * n;
        int f, g;
        f = max(0, L - r);
        g = max(R, r) * 2 - r - R + L - l - f;
        long long ans = inf;
        for(int m = 1; m <= n; m ++) {
            if(1ll * (m - 1) * g >= k) break;
            if(1ll * m * g >= k) {
                ans = min(ans, 1ll * m * f + k);
                continue;
            }
            if(1ll * m * g < k) {
                long long q = 1ll * m * f + 1ll * m * g;
                int p = k - m * g;
                q += 2 * p;
                ans = min(ans, q);
            }
        }
        printf("%I64d\n", ans);
    }
}