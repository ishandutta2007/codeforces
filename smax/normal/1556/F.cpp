#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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
using M = ModInt<1000000007>;
// using M = double;

gp_hash_table<int, M> ff[1 << 14];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), bruh(1 << n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        bruh[1 << i] = a[i];
    }

    vector<vector<M>> over(n, vector<M>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            over[i][j] = inverse(M(a[i] + a[j]));

    for (int mask=0; mask<1<<n; mask++)
        for (int sub=mask; sub>0; sub=(sub-1)&mask) {
            ff[mask][sub] = 1;
            M &cur = ff[mask][sub];
            int nmask = mask ^ sub;
            int xx = nmask;
            while (xx > 0) {
                int x = xx & -xx;
                xx -= x;
                int yy = sub;
                while (yy > 0) {
                    int y = yy & -yy;
                    yy -= y;
                    DEBUG(x, y);
                    // x is inside, y is outside
                    cur *= M(bruh[y]) * over[__lg(x)][__lg(y)];
                }
            }
        }

    M ret = 0;
    for (int u=0; u<n; u++) {
        // auto getIndex = [&] (int v) -> int {
        //     assert(u != v);
        //     return v < u ? v : v - 1;
        // };

        // probability that you can reach at least nodes in mask
        vector<M> dp(1 << n, 1);
        // // probability that you can reach at most nodes in mask
        vector<M> dp2(1 << n, 1);
        for (int mask=0; mask<1<<n; mask++) {
            if ((~mask >> u) & 1)
                continue;
            // if (mask == 0) {
            //     dp[mask] = 1;
            //     continue;
            // }
            // at least = 1 - PIE on at most
            for (int sub=mask; sub>0; sub=(sub-1)&mask) {
                int nmask = mask ^ sub;
                if ((sub >> u) & 1)
                    continue;
                M factor = ff[mask][sub];
                DEBUG(mask, sub);
                // vector<int> inside, outside;
                // for (int v=0; v<n; v++) {
                //     if (v == u || (nmask >> getIndex(v)) & 1)
                //         inside.push_back(v);
                //     else if ((mask >> getIndex(v)) & 1)
                //         outside.push_back(v);
                // }
                // for (int i=0; i<(int)inside.size(); i++)
                //     for (int j=0; j<(int)outside.size(); j++)
                //         factor *= M(a[outside[j]]) / (a[inside[i]] + a[outside[j]]);
                // if (__builtin_parity(sub))
                //     dp[mask] -= factor * dp[nmask];
                // else
                    dp[mask] -= factor * dp[nmask];
            }
            // for (int x=0; x<n; x++)
            //     if (x == u || (mask >> getIndex(x)) & 1)
            //         for (int y=0; y<n; y++)
            //             if (y != u && (~mask >> getIndex(y)) & 1)
            //                 dp2[mask] *= M(a[y]) / (a[x] + a[y]);
            // how tf do you calculate at most?

        }
        DEBUG(u, dp, dp2);
        // DEBUG(u, dp);
        ret += dp[(1 << n) - 1];
    }
    cout << ret << "\n";

    return 0;
}