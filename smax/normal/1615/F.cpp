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
using M = ModInt<1000000007>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        vector<vector<M>> pref(n + 1, vector<M>(2 * n + 1));
        pref[0][n] = 1;
        for (int i=0; i<n; i++) {
            if (i % 2 == 0) {
                if (s[i] != '?') s[i] = s[i] == '0' ? '1' : '0';
                if (t[i] != '?') t[i] = t[i] == '0' ? '1' : '0';
            }
            for (int j=-i; j<=i; j++)
                for (int a=0; a<2; a++)
                    if (s[i] == '?' || s[i] - '0' == a)
                        for (int b=0; b<2; b++)
                            if (t[i] == '?' || t[i] - '0' == b)
                                pref[i+1][j+a-b+n] += pref[i][j+n];
        }

        vector<vector<M>> suff(n + 1, vector<M>(2 * n + 1));
        suff[n][n] = 1;
        for (int i=n-1; i>=0; i--)
            for (int j=-n+i+1; j<=n-i-1; j++)
                for (int a=0; a<2; a++)
                    if (s[i] == '?' || s[i] - '0' == a)
                        for (int b=0; b<2; b++)
                            if (t[i] == '?' || t[i] - '0' == b)
                                suff[i][j+a-b+n] += suff[i+1][j+n];

        M ret = 0;
        for (int i=0; i<n; i++)
            for (int j=-n; j<=n; j++)
                ret += pref[i][j+n] * suff[i][-j+n] * abs(j);
        cout << ret << "\n";
    }

    return 0;
}