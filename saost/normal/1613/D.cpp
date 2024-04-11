#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 500005, MOD = 998244353;
int t, n, a[N], f[N][2], res;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        int x;
        for(int i=0; i<=n+1; ++i) f[i][0] = f[i][1] = 0;
        for(int i=1; i<=n; ++i) {
            int v = a[i];
            f[v][0] = (f[v][0] * 2 % MOD + f[v - 1][0]) % MOD;
            if (v > 0) (f[v - 1][1] *= 2) %= MOD;
            if (v > 1) (f[v - 1][1] += f[v - 2][0]) %= MOD;
            (f[v + 1][1] *= 2) %= MOD;
            if (v <= 1) ++f[0][v];
        }
        res = 0;
        for(int i=0; i<=n; ++i) (res += (f[i][0] + f[i][1]) % MOD) %= MOD;
        cout << res << '\n';
    }
}