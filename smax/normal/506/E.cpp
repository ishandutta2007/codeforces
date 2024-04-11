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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
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
    friend istream& operator >> (istream &is, ModInt &m) {is >> m.v; m.v = (-MOD < m.v && m.v < MOD) ? m.v : m.v % MOD; if (m.v < 0) m.v += MOD; return is;}
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
typedef ModInt<10007> M;

template<typename T>
vector<T> berlekampMassey(const vector<T> &s) {
    int n = (int) s.size(), l = 0, m = 1;
    vector<T> b(n), c(n);
    T ld = b[0] = c[0] = 1;
    for (int i=0; i<n; i++, m++) {
        T d = s[i];
        for (int j=1; j<=l; j++)
            d += c[j] * s[i-j];
        if (d == 0)
            continue;
        vector<T> temp = c;
        T coef = d / ld;
        for (int j=m; j<n; j++)
            c[j] -= coef * b[j-m];
        if (2 * l <= i) {
            l = i + 1 - l;
            b = temp;
            ld = d;
            m = 0;
        }
    }
    c.resize(l + 1);
    c.erase(c.begin());
    for (T &x : c)
        x = -x;
    return c;
}

template<typename T>
T solve(const vector<T> &c, const vector<T> &s, long long n) {
    int m = (int) c.size();
    assert(c.size() <= s.size());

    auto mul = [&] (const vector<T> &a, const vector<T> &b) -> vector<T> {
        vector<T> ret(a.size() + b.size() - 1);
        for (int i=0; i<(int)a.size(); i++)
            for (int j=0; j<(int)b.size(); j++)
                ret[i+j] += a[i] * b[j];
        for (int i=(int)ret.size()-1; i>=m; i--)
            for (int j=m-1; j>=0; j--)
                ret[i-j-1] += ret[i] * c[j];
        ret.resize(min((int) ret.size(), m));
        return ret;
    };

    vector<T> a = m == 1 ? vector<T>{c[0]} : vector<T>{0, 1}, x{1};
    for (; n>0; n/=2) {
        if (n % 2)
            x = mul(x, a);
        a = mul(a, a);
    }
    x.resize(m);

    T ret = 0;
    for (int i=0; i<m; i++)
        ret += x[i] * s[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n;
    cin >> s >> n;
    int m = (int) s.size();
    n += m;
    string t(s.rbegin(), s.rend());

    vector<vector<M>> dp(m + 1, vector<M>(m + 1)), ndp(m + 1, vector<M>(m + 1));
    vector<M> seq{0};
    dp[0][0] = 1;
    for (int i=0; i<min(n/2, 2500); i++) {
        for (int l=0; l<=m; l++)
            for (int r=0; r<=m; r++)
                ndp[l][r] = 0;
        for (int l=0; l<=m; l++)
            for (int r=0; r<=m; r++) {
                if (l == m && r == m) {
                    ndp[l][r] += dp[l][r] * 26;
                } else if (l == m) {
                    ndp[l][r] += dp[l][r] * 25;
                    ndp[l][r+1] += dp[l][r];
                } else if (r == m) {
                    ndp[l][r] += dp[l][r] * 25;
                    ndp[l+1][r] += dp[l][r];
                } else if (s[l] == t[r]) {
                    ndp[l][r] += dp[l][r] * 25;
                    ndp[l+1][r+1] += dp[l][r];
                } else {
                    ndp[l][r] += dp[l][r] * 24;
                    ndp[l+1][r] += dp[l][r];
                    ndp[l][r+1] += dp[l][r];
                }
            }
        dp.swap(ndp);
        M cur = 0;
        for (int l=0; l<=m; l++)
            for (int r=0; r<=m; r++) {
                if (n % 2) {
                    if (l + r >= m)
                        cur += dp[l][r] * 26;
                    else if (l + r == m - 1)
                        cur += dp[l][r];
                } else {
                    if (l + r >= m)
                        cur += dp[l][r];
                }
            }
        seq.push_back(cur);
    }

    if (n / 2 < (int) seq.size())
        cout << seq[n / 2] << "\n";
    else
        cout << solve(berlekampMassey(seq), seq, n / 2) << "\n";

    return 0;
}