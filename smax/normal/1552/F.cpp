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
typedef ModInt<998244353> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> x(n), y(n), s(n);
    for (int i=0; i<n; i++)
        cin >> x[i] >> y[i] >> s[i];

    // dp[i] - time it takes to get to x_i and not teleport
    // dp2[i] - always on version
    map<int, M> dp{{x[0], x[0] + (s[0] ? x[0] - y[0] : 0)}}, dp2{{x[0], x[0] + x[0] - y[0]}};
    for (int i=1; i<n; i++) {
        if (s[i]) {
            auto it = dp.lower_bound(y[i]);
            if (it == dp.end()) {
                dp[x[i]] = dp[x[i-1]] + x[i] - x[i-1] + x[i] - y[i];
            } else if (it == dp.begin()) {
                dp[x[i]] = dp[x[i-1]] + x[i] - x[i-1] + dp2[x[i-1]] + x[i] - x[i-1] - y[i];
            } else {
                int xx = prev(it)->first;
                dp[x[i]] = dp[x[i-1]] + x[i] - x[i-1] + dp2[x[i-1]] + x[i] - x[i-1] - dp2[xx] - y[i] + xx;
            }
        } else {
            dp[x[i]] = dp[x[i-1]] + x[i] - x[i-1];
        }
        auto it = dp2.lower_bound(y[i]);
        if (it == dp2.end()) {
            dp2[x[i]] = dp2[x[i-1]] + x[i] - x[i-1] + x[i] - y[i];
        } else if (it == dp2.begin()) {
            dp2[x[i]] = dp2[x[i-1]] + x[i] - x[i-1] + dp2[x[i-1]] + x[i] - x[i-1] - y[i];
        } else {
            int xx = prev(it)->first;
            dp2[x[i]] = dp2[x[i-1]] + x[i] - x[i-1] + dp2[x[i-1]] + x[i] - x[i-1] - dp2[xx] - y[i] + xx;
        }
    }
    cout << dp[x[n-1]] + 1 << "\n";

    return 0;
}