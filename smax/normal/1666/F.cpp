#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"

template<int MOD>
struct ModInt {
    long long v;
    ModInt(long long _v = 0) {v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD;}
    ModInt& operator += (const ModInt &other) {v += other.v; if (v >= MOD) v -= MOD; return *this;}
    ModInt& operator -= (const ModInt &other) {v -= other.v; if (v < 0) v += MOD; return *this;}
    ModInt& operator *= (const ModInt &other) {v = v * other.v % MOD; return *this;}
    ModInt& operator /= (const ModInt &other) {return *this *= inverse(other);}
    bool operator == (const ModInt &other) const {return v == other.v;}
    bool operator != (const ModInt &other) const {return v != other.v;}
    friend ModInt operator + (ModInt a, const ModInt &b) {return a += b;}
    friend ModInt operator - (ModInt a, const ModInt &b) {return a -= b;}
    friend ModInt operator * (ModInt a, const ModInt &b) {return a *= b;}
    friend ModInt operator / (ModInt a, const ModInt &b) {return a /= b;}
    friend ModInt operator - (const ModInt &a) {return 0 - a;}
    friend ModInt power(ModInt a, long long b) {ModInt ret(1); while (b > 0) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
    friend ModInt inverse(ModInt a) {return power(a, MOD - 2);}
    friend istream& operator >> (istream &is, ModInt &m) {is >> m.v; m.v = (-MOD < m.v && m.v < MOD) ? m.v : m.v % MOD; if (m.v < 0) m.v += MOD; return is;}
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};

const int mod = 998244353;
const int maxn = 5005;
typedef ModInt<mod> M;

M fact[maxn];



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = fact[i-1] * M(i);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> elts;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            elts.pb(x);
            a[i] = x;
        }
        sort(elts.begin(), elts.end());
        elts.erase(unique(elts.begin(), elts.end()), elts.end());
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(elts.begin(), elts.end(), a[i]) - elts.begin() + 1;
        }
        int mx = (int)elts.size();
        vector<M> cnt(mx+1);
        vector<M> pre(mx+1);
        for (int i = 1; i <= n; i++) {
            cnt[a[i]] = cnt[a[i]] + 1;
        }
        for (int i = 1; i <= mx; i++) {
            pre[i] = pre[i-1] + cnt[i];
        }
        vector<vector<M>> dp(mx+1, vector<M>(n/2 + 1));
        
        auto gaps = [&](int pref, int taken) -> M {
            return pre[pref-1] - 2 * taken + 1;
        };
        
        vector<vector<M>> dp2(mx+1, vector<M>(n/2+1));
        // for (int j = 1; j <= n/2; j++) {
            // dp2[2][j] = dp[2][j] * gaps[2][j];
            // for (int k = 3; k <= n / 2; k++) {
                // dp2[k][j] = dp2[k-1][j] + dp[k][j]
            // }
        // }
        
        
        dp[0][0] = 1;
        for (int i = 1; i <= mx; i++) {
            dp[i][0] = 1;
            dp[i][1] = cnt[i] * pre[i-1];
            for (int j = 2; j <= n/2; j++) {
                M dp_val = dp2[i-1][j-1];
                // for (int k = i - 1; k >= 2; k--) { // k is second to last
                    // dp_val += dp[k][j-1] * gaps(k, j-1);
                // }
                dp_val *= cnt[i];
                dp[i][j] = dp_val;
            }
            if (i == 2) {
                for (int j = 1; j <= n/2; j++) {
                    dp2[2][j] = dp[2][j] * gaps(2, j);
                }
            } else if (i > 2) {
                for (int j = 1; j <= n/2; j++) {
                    dp2[i][j] = dp2[i-1][j] + dp[i][j] * gaps(i, j);
                }
            }
            
        }
        // cout << "mx: " << mx << "\n";
        // cout << "dp:\n";
        // for (int i = 0; i <= 4; i++) {
            // for (int j = 0; j <= 2; j++) {
                // cout << dp[i][j] << " ";
            // }
            // cout << "\n";
        // }
        M div = 1;
        for (int i = 1; i <= mx; i++) {
            div *= fact[cnt[i].v];
        }
        M ans = dp[mx][n/2] / div;
        cout << ans << "\n";
    }
    
    return 0;
}