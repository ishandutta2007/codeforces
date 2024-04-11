#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

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

int a[100005];
M dp[100005][205][2], pref[205][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    // i - pos
    // j - val
    // k - whether or not you need to be >= previous value
    for (int j=1; j<=200; j++) {
        dp[0][j][1] = (a[0] == -1 ? 1 : a[0] == j);
        pref[j][1] = pref[j-1][1] + dp[0][j][1];
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<=200; j++) {
            if (a[i] != -1 && a[i] != j)
                continue;
            // case 1: > prev -> needs next val to be >= it
            dp[i][j][1] += pref[j-1][0] + pref[j-1][1];
            // case 2: = prev -> no restriction on next val
            dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][1];
            // case 3: < prev -> no restriction on next val
            dp[i][j][0] += pref[200][0] - pref[j][0];
        }
        for (int j=1; j<=200; j++)
            for (int k=0; k<2; k++)
                pref[j][k] = pref[j-1][k] + dp[i][j][k];
    }

    M ret = 0;
    for (int j=1; j<=200; j++)
        ret += dp[n-1][j][0];

    cout << ret << "\n";

    return 0;
}