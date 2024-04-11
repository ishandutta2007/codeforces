#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = (int)2e5 + 50;
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


typedef tree<
        pair<ll, int>,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set ;

int n;
ll a[N];

struct NSet {
    ordered_set S;
    ll off = 0;
    int t = 0;

    void clear() {
        S.clear();
        off = 0;
        t = 0;
    }

    void add(ll val) {
        off += val;
    }

    void insert(ll val) {
        S.insert({val - off, t++});
    }

    int find_under(ll val) {
        return S.order_of_key({val - off, -1});
    }
} nset[2];

ll psum[N];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        nset[0].clear();
        nset[1].clear();
        rep(i, 1, n + 1) cin >> a[i], psum[i] = psum[i - 1] + a[i];
        mi res = 0;
        if(n <= 3) {
            rep(mask, 0, (1 << n)) {
                ll r = 0;
                rep(i, 0, n) {
                    if(mask >> i & 1) r += a[i + 1];
                    else r -= a[i + 1];
                }
                if(r < 0) res += 1;
            }
            cout << int(res) << '\n';
            continue;
        }


        for(int i = n - 1; i >= 1; i--) {
            res += (psum[n] - psum[i - 1] - psum[i - 1] < 0);
        }
//        cout << int(res) << '\n';

        nset[(n + 1) % 2].insert(0);
        for(int i = n; i >= 1; i--) {
            nset[i % 2].add(-a[i] + a[i + 1]);
            nset[i % 2].insert(-(psum[n] - psum[i - 1]));
            if(i <= n - 2) nset[i % 2].insert(-(psum[n] - psum[i - 1]) + 2 * a[n]);

            mi cres = 0;
            cres += nset[i % 2].find_under(-psum[i - 1]);
            if(i >= 4) cres += nset[i % 2].find_under(-psum[i - 1] + 2 * a[1]);
//            cout << i << " " << int(cres) << '\n';
            res += cres;
        }
        cout << int(res) << '\n';
    }

}