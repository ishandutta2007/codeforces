#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
ll a[MAXN], w[MAXN], conv[MAXN];

struct BIT {
    ll b[MAXN];
    bool mod;

    void upd(int p, ll v) {
        for(; p < MAXN; p += (p & -p)) {
            b[p] += v;
            if(mod)
                b[p] %= MOD;
        }
    }

    ll sum(int p) {
        ll res = 0;
        for(; p; p -= (p & -p)) {
            res += b[p];
            if(res >= MOD && mod)
                res -= MOD;
        }
        return res;
    }

    ll sum(int l, int r) {
        if(l > r)
            return 0;
        return sum(r) - sum(l - 1);
    }
};

BIT wBIT, convBIT, progBIT;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    convBIT.mod = true;
    progBIT.mod = true;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        wBIT.upd(i, w[i]);
        progBIT.upd(i, (ll)i * w[i]);
        convBIT.upd(i, w[i] * a[i]);
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(x < 0) {
            x *= -1;
            ll d = (ll)y - w[x];
            wBIT.upd(x, d);
            progBIT.upd(x, d * x);
            convBIT.upd(x, d * a[x]);
            w[x] = y;
        }
        else {
            if(x == y) {
                cout << "0\n";
                continue;
            }
            int lo = x, hi = y;
            while(lo < hi) {
                int mi = (lo + hi + 1)/2;
                if(wBIT.sum(mi + 1, y) >= wBIT.sum(x, mi))
                    lo = mi;
                else
                    hi = mi - 1;
            }
            lo++;
            if(wBIT.sum(x + 1, y) < w[x])
                lo = x;
            ll ans = 0;
            ans += convBIT.sum(lo + 1, y);
            //cout << ans << '\n';
            ans -= progBIT.sum(lo + 1, y);
            ans += (ll)(lo - a[lo])*(wBIT.sum(lo + 1, y) % MOD);
            ans %= MOD;
            //cout << ans << '\n';
            ans -= convBIT.sum(x, lo - 1);
            ans += progBIT.sum(x, lo - 1);
            ans += (ll)(a[lo] - lo)*(wBIT.sum(x, lo - 1) % MOD);
            ans %= MOD;
            cout << (ans + MOD) % MOD << '\n';
        }
    }
}