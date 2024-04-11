#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;
ll ev[MAXN], pf[MAXN], l[MAXN], r[MAXN], S;

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b)%MOD;
        b = (b * b)%MOD;
    }
    return res;
}

ll inv(ll b) {
    return mpow(b, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> l[i];
    for(int i = 1; i <= n; i++)
        cin >> r[i];
    if(n == 1) {
        cout << "1\n";
        return 0;
    }
    int k = n - 1;
    ev[0] = 0;
    for(int i = 0; i < n; i++) {
        ll m = max(l[i], l[i + 1]), M = min(r[i], r[i + 1]);
        ll tot = ((r[i] - l[i] + 1) * (r[i + 1] - l[i + 1] + 1))%MOD;
        ev[i] = ((tot - max(0LL, M - m + 1))*inv(tot))%MOD;
        pf[i] = (i ? pf[i - 1] + ev[i] : ev[i]) % MOD;
        //cout << i << " " << ev[i] << "\n";
    }
    ll S = 0;
    for(int i = 0; i < n; i++)
        S = (S + ev[i]) % MOD;
    ll ans = S;
    for(int i = 2; i < n; i++) 
        ans = (ans + 2LL * ev[i] * pf[i - 2])%MOD;
    //cout << S << " " << ans << endl;
    ll expected;
    for(int i = 0; i <= k - 1; i++) {
        ll len1 = (r[i] - l[i] + 1), len2 = (r[i + 1] - l[i + 1] + 1), len3 = (r[i + 2] - l[i + 2] + 1);
        ll c1 = max(0LL, min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1), c2 = max(0LL, min(r[i + 1], r[i + 2]) - max(l[i + 1], l[i + 2]) + 1), c3 = max(0LL, min({r[i], r[i + 1], r[i + 2]}) - max({l[i], l[i + 1], l[i + 2]}) + 1);
        ll cases = ((len1 * len2)%MOD * len3)%MOD, viable = cases;
        //cout << viable << " " << cases << endl;
        viable = (viable - c1*len3) % MOD;
        //cout << viable << " " << cases << endl;
        viable = (viable - c2*len1) % MOD;
        //cout << viable << " " << cases << endl;
        viable = (viable + c3) % MOD;
        //cout << viable << " " << cases << endl;
        expected = (viable * inv(cases)) % MOD;
        ans = (ans + 2LL * expected) % MOD;
    }
    if(ans < 0)
        ans += MOD;
    cout << ans << endl;
}