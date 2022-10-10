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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int MOD;
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

ModInt dp[3][405][405], pref1[405], pref2[405], pref3[405], pref4[405], pref5[405];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> MOD;

    // first i, length, rank of last
    // 0, 1, 0
    dp[0][1][0] = dp[1][2][0] = dp[1][2][1] = 1;
    for (int i=2; i<n; i++) // first i
        for (int j=1; j<=i+1; j++) {    // length
            for (int l=0; l<j; l++) {
                pref1[l] = dp[(i-2)%3][j-1][l] + (l > 0 ? pref1[l-1] : 0);
                pref2[l] = dp[(i-1)%3][j-1][l] + (l > 0 ? pref2[l-1] : 0);
                if (j >= 2) {
                    // pref3[l] = dp[i-2][j-2][l] * max(j - l - 1, 0) + (l > 0 ? pref3[l-1] : 0);
                    pref4[l] = dp[(i-2)%3][j-2][l] * max(j - (l + 1) - 1, 0) + (l > 0 ? pref4[l-1] : 0);
                    pref5[l] = dp[(i-2)%3][j-2][l] + (l > 0 ? pref5[l-1] : 0);
                }
            }
            for (int k=0; k<j; k++) {   // rank
                // // ... v _ v
                // for (int l=0; l<j; l++)
                //     dp[i][j][k] += dp[i-2][j-1][l];
                // // ... v v
                // for (int l=0; l<j; l++)
                //     dp[i][j][k] += dp[i-1][j-1][l];
                // if (j >= 2)
                //     for (int l=0; l<j-1; l++)   // last one is after l and k
                //         dp[i][j][k] -= dp[i-2][j-2][l] * max(j - max(l + (l >= k), k) - 1, 0);
                dp[i%3][j][k] = 0;
                dp[i%3][j][k] += pref1[j-1];
                dp[i%3][j][k] += pref2[j-1];
                if (j >= 2) {
                    // part 1: l + (l >= k) < k -> l < k
                    if (k > 0) dp[i%3][j][k] -= pref5[min(k-1, j-2)] * max(j - k - 1, 0);
                    // part 2: l + (l >= k) >= k -> l >= k
                    if (k - 1 < j - 2) dp[i%3][j][k] -= pref4[j-2] - (k > 0 ? pref4[k-1] : 0);
                }
            }
        }

    ModInt ret = 0;
    for (int j=1; j<=n; j++)
        for (int k=0; k<j; k++)
            ret += dp[(n-1)%3][j][k];
    cout << ret << "\n";

    return 0;
}