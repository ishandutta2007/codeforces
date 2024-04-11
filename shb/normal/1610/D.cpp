#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
int main() {
    int n;
    auto quick_pow = [](int a, int x) {
        int ret = 1;
        while(x) {
            if (x & 1) ret = 1LL * ret * a % MOD;
            a = 1LL * a * a % MOD;
            x >>= 1;
        }
        return ret;
    };
    
    scanf("%d",&n);
    vector<int>fac(n + 1), ifac(n + 1), po(n + 1);
    fac[0] = ifac[0] = 1;
    po[0] = 1;
    for (int i = 1; i <= n; i++) {
        po[i] = 2 * po[i - 1] % MOD;
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = quick_pow(fac[i], MOD - 2);
    }
    auto C = [&](int n, int k) -> int{
        if (k > n || k < 0) return 0;
        return 1LL * fac[n] * ifac[n - k] % MOD * ifac[k] % MOD;
    };
    vector<int> a(n);
    vector<int> cnt(32);
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        int tmp = a[i], t = 0;
        while(tmp % 2 == 0) {
            tmp /= 2;
            t++;
        }
        cnt[t]++;
    }    
    int ans = 1LL * po[n - cnt[0]] * (po[cnt[0]] - 1) % MOD;
    int S = n - cnt[0];
    for (int i = 1; i < 32; i++) {
        int tmp = 0;
        S -= cnt[i];
        for (int j = 2; j <= cnt[i]; j += 2) {
            tmp = (tmp + C(cnt[i], j)) % MOD;
        }
        ans = (ans + 1LL * tmp * po[S]) % MOD;
    }
    printf("%d\n",ans);
}