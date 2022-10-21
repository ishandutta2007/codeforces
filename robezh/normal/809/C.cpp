#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)5e5 + 50;
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

typedef pair<mi, mi> pmi;


int a, b, k;
bool vis[31][2][2][2];
mi dp[31][2][2][2], sdp[31][2][2][2];
mi tres = 0;

pmi solve(int bt, int ae, int be, int ke) {
    if(bt == -1) return {1, 0};
    if(vis[bt][ae][be][ke]) return {dp[bt][ae][be][ke], sdp[bt][ae][be][ke]};
    dp[bt][ae][be][ke] = sdp[bt][ae][be][ke] = 0;
    vis[bt][ae][be][ke] = true;
    int u1 = (ae && !(a >> bt & 1)) ? 0 : 1;
    int u2 = (be && !(b >> bt & 1)) ? 0 : 1;
    for(int b1 = 0; b1 <= u1; b1++) {
        for(int b2 = 0; b2 <= u2; b2++) {
            int b3 = (b1 ^ b2);
            int u3 = (k >> bt & 1);
            if(!ke || b3 <= u3) {
                pmi nxt = solve(bt - 1, ae && b1 == u1, be && b2 == u2, ke && b3 == u3);
                dp[bt][ae][be][ke] += nxt.first;
                sdp[bt][ae][be][ke] += nxt.first * (1 << bt) * b3 + nxt.second;
            }

        }
    }
    return {dp[bt][ae][be][ke], sdp[bt][ae][be][ke]};
}

mi calc(int x, int y) {
    if(x < 0 || y < 0) return 0;
//    mi res = 0;
//    for(int i = 0; i <= x; i++) {
//        for(int j = 0; j <= y; j++) if((i ^ j) <= k) res += (i ^ j) + 1;
//    }
//    return res;
    a = x, b = y;
    memset(vis, 0, sizeof(vis));
    return solve(30, 1, 1, 1).second + solve(30, 1, 1, 1).first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        x1--, y1--, x2--, y2--, k--;
        mi res = calc(x2, y2) - calc(x2, y1 - 1) - calc(x1 - 1, y2) + calc(x1 - 1, y1 - 1);
        cout << int(res) << '\n';
    }

}