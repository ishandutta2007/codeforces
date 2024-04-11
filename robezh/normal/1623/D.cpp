#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;

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

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        int si, sj, ti, tj, x;
        cin >> si >> sj >> ti >> tj >> x;
        mi p = (mi)x / 100;
//        ll lcm = 2LL * (n - 1) * (m - 1) / __gcd((n - 1), (m - 1));
        vi ps;
        for (int rd = 0; rd < m - 1; rd++) {
            if(si <= ti) {
                ps.push_back(rd * (2 * n - 2) + ti - si);
                if(ti != 1 && ti != n) ps.push_back(rd * (2 * n - 2) + (n - ti) + (n - si));
            } else {
                ps.push_back(rd * (2 * n - 2) + (n - ti) + (n - si));
                if(ti != 1 && ti != n) ps.push_back(rd * (2 * n - 2) + (n - ti) + (n - si) + (ti - 1) * 2);
            }
        }
//        for (int t : ps) {
//            cout << t << " ";
////            sum += (pw * p) * t;
////            pw *= (1 - p);
//        }
//        cout << endl;
//        ps.clear();
        for (int rd = 0; rd < n - 1; rd++) {
            if(sj <= tj) {
                ps.push_back(rd * (2 * m - 2) + tj - sj);
                if(tj != 1 && tj != m) ps.push_back(rd * (2 * m - 2) + (m - tj) + (m - sj));
            } else {
                ps.push_back(rd * (2 * m - 2) + (m - tj) + (m - sj));
                if(tj != 1 && tj != m) ps.push_back(rd * (2 * m - 2) + (m - tj) + (m - sj) + (tj - 1) * 2);
            }
        }
//        for (int t : ps) {
//            cout << t << " ";
//            sum += (pw * p) * t;
//            pw *= (1 - p);
//        }
//        cout << endl;

        sort(all(ps));
        ps.resize(unique(all(ps)) - ps.begin());

        mi sum = 0, pw = 1;
        for (int t : ps) {
//            cout << t << " ";
            sum += (pw * p) * t;
            pw *= (1 - p);
        }

//        assert(pw == mi(9) / 16);

//        cout << endl;
        mi res = (sum + pw * 2 * (n - 1) * (m - 1)) / (1 - pw);
        cout << int(res) << '\n';
    }
}