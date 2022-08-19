#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int n;
vector<pi> cur;
multiset<ll> l, r;
const ll inf = 1e18;
int main() {
    cin >> n;
    ll inc = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        cur.pb(mp(x + y, x));
    }
    sort(cur.begin(), cur.end());
    l.insert(0), r.insert(0);
    ll ls = 0;
    ll ans = 0;
    for (auto v : cur) {
        inc += v.fi - ls;
        ls = v.fi;
        ll lm = *l.rbegin(), rm = (*r.begin()) + inc;
        int x = v.se;
        //cout << lm << ' ' << x << ' ' << rm << ' ' << inc << endl;
        if (lm <= x && x <= rm) l.insert(x), r.insert(x - inc);
        else if (x < lm) {
            r.insert(lm - inc);
            l.erase(l.find(lm));
            l.insert(x), l.insert(x);
            ans += abs(x - lm);
        }
        else {
            r.erase(r.find(rm - inc));
            r.insert(x - inc), r.insert(x - inc);
            l.insert(rm);
            ans += abs(x - rm);
        }
    }
    cout << ans << endl;
    return 0;
}