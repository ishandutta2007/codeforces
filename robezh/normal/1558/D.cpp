#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)4e5 + 50, INF = (int)1e9;

typedef long long ll;
const int MOD = (int)998244353;

struct mi {
    typedef decay<decltype(MOD)>::type T;
    /// don't silently convert to T
    T v; explicit operator T() const { return v; }
    mi() { v = 0; }
    mi(ll _v) {
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mi& a, const mi& b) {
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) {
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) {
        return a.v < b.v; }
//    friend void re(mi& a) { ll x; re(x); a = mi(x); }
//    friend str ts(mi a) { return ts(a.v); }

    mi& operator+=(const mi& m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this; }
    mi& operator*=(const mi& m) {
        v = (ll)v*m.v%MOD; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a.v != 0);
        return pow(a,MOD-2); }

    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};


mi fac[N];

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

typedef tree<
        int,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set ;

int n, m;

mi facinv[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;
    facinv[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1);


    ordered_set S;
    rep(i, 1, (int)2e5 + 1) S.insert(i);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        vi del;


        vector<pii> vs;
        rep(i, 0, m) {
            int x, y; cin >> x >> y;
            vs.push_back({x, y});
        }
        reverse(all(vs));
        int la = n + 1;
        int sum = 0;
        map<int, int> badpos;
        for(auto p : vs) {
            sum += la - p.first - 1;
            auto it = S.find_by_order(p.second - 1);
            del.push_back(*it);
            it = S.erase(it);
            if(it != S.end()) {
//                cout << *it << " bad" << endl;
                badpos[*it] = 1;
            }
            la = p.first;
        }
//        cout << sz(badpos) << endl;
        mi res = fac[2 * n - sz(badpos) - 1] * facinv[n] * facinv[n - sz(badpos) - 1];
        cout << int(res) << '\n';

        for (auto x : del) S.insert(x);
    }

}