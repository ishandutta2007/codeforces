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

const int MAXN = 405;
const int ALPHA = 26;

M dp1[MAXN][2][2], ndp1[MAXN][2][2], dp2[MAXN][MAXN][3][3], ndp2[MAXN][MAXN][3][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> c(ALPHA);
    for (int i=0; i<ALPHA; i++)
        cin >> c[i];

    dp1[0][0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i+1; j++)
            for (int k=0; k<2; k++)
                for (int l=0; l<2; l++)
                    ndp1[j][k][l] = 0;
        for (int j=0; j<=i; j++)
            for (int k=0; k<2; k++)
                for (int l=0; l<2; l++)
                    if (dp1[j][k][l].v) {
                        ndp1[j][l][0] += dp1[j][k][l] * (ALPHA - 1 - (k == 0 && i >= 2));
                        if (k == 0)
                            ndp1[j+1][l][1] += dp1[j][k][l];
                    }
        memcpy(dp1, ndp1, sizeof(ndp1));
    }
    for (int k=0; k<2; k++)
        for (int l=0; l<2; l++)
            for (int j=n-1; j>=0; j--)
                dp1[j][k][l] += dp1[j+1][k][l];

    dp2[0][0][0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i+1; j++)
            for (int k=0; k<=i+1-j; k++)
                for (int l=0; l<3; l++)
                    for (int m=0; m<3; m++)
                        ndp2[j][k][l][m] = 0;
        for (int j=0; j<=i; j++)
            for (int k=0; k<=i-j; k++)
                for (int l=0; l<3; l++)
                    for (int m=0; m<3; m++)
                        if (dp2[j][k][l][m].v) {
                            ndp2[j][k][m][0] += dp2[j][k][l][m] * (ALPHA - 2 - (l == 0 && i >= 2));
                            if (l != 1)
                                ndp2[j+1][k][m][1] += dp2[j][k][l][m];
                            if (l != 2)
                                ndp2[j][k+1][m][2] += dp2[j][k][l][m];
                        }
        memcpy(dp2, ndp2, sizeof(ndp2));
    }
    for (int l=0; l<3; l++)
        for (int m=0; m<3; m++)
            for (int j=n; j>=0; j--)
                for (int k=n; k>=0; k--) {
                    if (j < n)
                        dp2[j][k][l][m] += dp2[j+1][k][l][m];
                    if (k < n)
                        dp2[j][k][l][m] += dp2[j][k+1][l][m];
                    if (j < n && k < n)
                        dp2[j][k][l][m] -= dp2[j+1][k+1][l][m];
                }

    M ret = 26 * 26;
    for (int i=0; i<n-2; i++)
        ret *= 25;
    for (int i=0; i<26; i++)
        if (c[i] < n) {
            for (int k=0; k<2; k++)
                for (int l=0; l<2; l++)
                    ret -= dp1[c[i] + 1][k][l];
            for (int j=i+1; j<26; j++)
                if (c[j] < n)
                    for (int l=0; l<3; l++)
                        for (int m=0; m<3; m++)
                            ret += dp2[c[i] + 1][c[j] + 1][l][m];
        }
    cout << ret << "\n";

    return 0;
}