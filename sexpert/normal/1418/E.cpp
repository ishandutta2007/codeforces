#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
const ll MOD = 998244353;
ll inv[MAXN];

ll _inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 1; i < MAXN; i++)
        inv[i] = _inv(i);

    int n, m;
    cin >> n >> m;
    vector<ll> d(n), psum(n);

    for(auto &x: d)
        cin >> x;
    sort(d.begin(), d.end());
    for(int i = 0; i < n; i++)
        psum[i] = d[i] + (i ? psum[i - 1] : 0);

    for(int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        if(d.back() < b) {
            cout << "0\n";
            continue;
        }
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mi = (lo + hi) / 2;
            if(d[mi] >= b)
                hi = mi;
            else
                lo = mi + 1;
        }
        ll small = lo, big = n - lo, sum_s = (lo ? psum[lo - 1] : 0) % MOD, sum_b = (psum[n - 1] - sum_s) % MOD;
        //cout << sum_s << " " << sum_b << endl;
        ll ans = ((sum_b * max(big - a, 0LL)) % MOD * inv[big]) % MOD;
        ans = (ans + (((sum_s * max(big - a + 1, 0LL)) % MOD) * inv[big + 1]) % MOD) % MOD;
        cout << ans << '\n';
    }
}