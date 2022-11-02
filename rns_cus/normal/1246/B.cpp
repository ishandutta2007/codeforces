#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, K, a[N];

typedef long long ll;

map <int, int> mp;

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        ll cur = 1, m = 1;
        for (int p = 2; p * p <= a[i]; p ++) {
            if (a[i] % p == 0) {
                int c = 0;
                while (a[i] % p == 0) a[i] /= p, c ++;
                c %= K;
                if (c == 0) continue;
                else {
                    for (int j = 0; j < c; j ++) cur *= p;
                    if (m < 0) continue;
                    for (int j = c; j < K; j ++) {
                        m *= p;
                        if (m > N) {
                            m = -1; break;
                        }
                    }
                }
            }
        }
        if (a[i] > 1) {
            cur *= a[i];
            if (m > 0) {
                for (int j = 1; j < K; j ++) {
                    m *= a[i];
                    if (m > N) {
                        m = -1; break;
                    }
                }
            }
        }
        if (m > 0) ans += mp[m];
        mp[cur] ++;
    }
    printf("%I64d\n", ans);

    return 0;
}