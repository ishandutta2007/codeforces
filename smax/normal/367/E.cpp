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
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
typedef ModInt<1000000007> M;

M dp[325][325], ndp[325][325];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;

    // if two intervals share the same l, the one with smaller r must be completely contained within the other
    // thus they must all have different l, so n > m implies no solution
    if (n > m) {
        cout << "0\n";
        return 0;
    }

    // since n <= m, n is at most sqrt(n * m), so O(n^2 m) dp works
    // position, number of open intervals, number of total intervals processed
    dp[0][0] = 1;
    for (int i=1; i<=m; i++) {
        for (int j=0; j<=n; j++)
            for (int k=0; k<=n; k++)
                ndp[j][k] = 0;
        for (int j=0; j<=n; j++)
            for (int k=0; k<=n; k++) {
                // start a new interval
                if (k < n)
                    ndp[j+1][k+1] += dp[j][k];
                // close earliest existing interval
                if (i != x && j > 0)
                    ndp[j-1][k] += dp[j][k];
                // start a new interval and close earliest existing interval
                if (j > 0 && k < n)
                    ndp[j][k+1] += dp[j][k];
                // create an interval just at [i, i]
                if (j == 0 && k < n)
                    ndp[j][k+1] += dp[j][k];
                // do nothing
                if (i != x)
                    ndp[j][k] += dp[j][k];
            }
        for (int j=0; j<=n; j++)
            for (int k=0; k<=n; k++)
                dp[j][k] = ndp[j][k];
    }

    M ret = dp[0][n];
    for (int i=1; i<=n; i++)
        ret *= i;
    cout << ret << "\n";

    return 0;
}