#include <iostream>
using namespace std;
const int N = 2e5 + 5, MOD = 998244353;
int t, n, maxi, cnt, cnt2, a[N];
long long res, tmp, f[N], f2[N], f3[N];

long long A(int n, int k) {
    if (n < k) return 0;
    return f[n] * f3[n-k] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    f[0] = f2[0] = f3[0] = f[1] = f2[1] = f3[1] = 1;
    for(int i=2; i<=200000; ++i) {
        f[i] = f[i-1] * i % MOD;
        f2[i] = MOD - MOD / i * f2[MOD % i] % MOD;
        f3[i] = f3[i-1] * f2[i] % MOD;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        maxi = cnt = cnt2 = 0;
        for(int i=1; i<=n; ++i) cin >> a[i], maxi = max(maxi, a[i]);
        for(int i=1; i<=n; ++i) {
            if (a[i] == maxi) ++cnt;
            if (a[i] == maxi - 1) ++cnt2;
        }
        if (cnt > 1) cout << f[n] << '\n';
        else if (cnt2 == 0) {
            if (maxi == 1) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else {
            cout << (f[n] - f[n] * f2[cnt2 + 1] % MOD + MOD) % MOD << '\n';
        }
    }
}