#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
const ll MOD = 1e9 + 7;
 
struct BIT {
    int n;
    vector<int> v;
    BIT(int n) : n(n) {
        v.resize(n + 1);
    }
    void upd(ll p, ll val) {
        for(; p <= n; p += (p & -p)) {
            v[p] += val;
            if(v[p] > MOD) v[p] -= MOD;
        }
    }
    ll qry(ll p) {
        ll res = 0;
        for(; p > 0; p -= (p & -p))
            res += v[p];
        return res%MOD;
    }
};
 
const int MAXN = 5e5 + 5;
BIT cl(MAXN), cr(MAXN);
 
int main() {
    int n;
    cin >> n;
    vector<ii> v;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back({a, i + 1});
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(auto p : v) {
        //cout << p.first << " " << p.second << endl;
        ll trib = ((ll)p.second)*((ll)(n - p.second + 1));
        trib %= MOD;
        //cout << "trib: " << trib << endl;
        //cout << n - p.second + 1 << endl;
        trib += (cl.qry(p.second))*((ll)(n - p.second + 1));
        trib += (cr.qry(n) - cr.qry(p.second - 1))*((ll)(p.second));
        //cout << "trib: " << trib << endl;
        trib %= MOD;
        if(trib < 0)
            trib += MOD;
        ans += ((ll)p.first) * trib;
        ans %= MOD;
        //cout << "live\n";
        cl.upd(p.second, p.second);
        cr.upd(p.second, n - p.second + 1);
        //cout << "live\n";
    }
    cout << ans << endl;
}