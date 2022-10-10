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
typedef ModInt<998244353> M;

// position in x, last character, have we taken from x, have we taken from y
M dp[1005][26][2][2], ndp[1005][26][2][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x, y;
    cin >> x >> y;
    int n = (int) x.size(), m = (int) y.size();

    M ret = 0;
    for (int k=0; k<26; k++)
        dp[n][k][1][1] = 1;
    for (int i=n-1; i>=0; i--)
        for (int k=0; k<26; k++) {
            dp[i][k][1][1] = 1;
            for (int a=0; a<2; a++)
                for (int b=0; b<2; b++) {
                    bool f = a == 0 && b == 0;
                    if ((f && k == 0) || (!f && x[i] - 'a' != k))
                        dp[i][k][a][b] += dp[i+1][x[i]-'a'][1][b];
                }
        }
    for (int j=m-1; j>=0; j--) {
        for (int i=0; i<=n; i++)
            for (int k=0; k<26; k++)
                for (int a=0; a<2; a++)
                    for (int b=0; b<2; b++)
                        ndp[i][k][a][b] = 0;
        for (int i=n; i>=0; i--)
            for (int k=0; k<26; k++)
                for (int a=0; a<2; a++)
                    for (int b=0; b<2; b++) {
                        bool f = a == 0 && b == 0;
                        // take character from x
                        if (i < n && ((f && k == 0) || (!f && x[i] - 'a' != k)))
                            ndp[i][k][a][b] += ndp[i+1][x[i]-'a'][1][b];
                        // take character from y
                        if ((f && k == 0) || (!f && y[j] - 'a' != k))
                            ndp[i][k][a][b] += dp[i][y[j]-'a'][a][1];
                        // terminate string here
                        if (a && b)
                            ndp[i][k][a][b] += 1;
                    }
        memcpy(dp, ndp, sizeof(ndp));
        for (int i=0; i<=n; i++)
            ret += dp[i][0][0][0];
    }
    cout << ret << "\n";

    return 0;
}