#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

const int N = (int)2e5 + 50;

int n, m, a[N], b[N];
set<pii> S;
int loc[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;

        S.clear();
        rep(i, 0, n) {
            cin >> a[i];
            a[i]--;
            loc[a[i]] = i;
            S.insert({i, a[i]});
        }
        mi res = 1;
        map<int, int> remb;
        rep(i, 0, m) {
            cin >> b[i];
            b[i]--;
            remb[b[i]]++;
        }

        rep(i, 0, m) {
            mi cur = 0;
            auto it = S.lower_bound({loc[b[i]], b[i]});
            if(it != S.begin()) {
                auto nit = it; nit--;
                if(!remb[nit -> second]) cur += 1;
            }
            {
                auto nit = it; nit++;
//                cout << b[i] << ", " << loc[b[i]] << " " << nit->second << endl;
                if(nit != S.end() && !remb[nit -> second]) cur += 1;
            }
//            cout << i << " " << int(cur) <<  endl;
            res *= cur;
            S.erase(it);
            remb[b[i]]--;
        }
        cout << int(res) << '\n';
    }

}