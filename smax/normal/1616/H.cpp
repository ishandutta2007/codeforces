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
using M = ModInt<998244353>;

M pw[150005];

M solve2(const vector<int> &a, const vector<int> &b, int x, int i) {
    if (a.empty() && b.empty())
        return 1;
    if (i == -1)
        return pw[a.size() + b.size()];
    vector<int> a0, a1, b0, b1;
    for (int y : a)
        (y >> i & 1 ? a1 : a0).push_back(y & ~(1 << i));
    for (int y : b)
        (y >> i & 1 ? b1 : b0).push_back(y & ~(1 << i));
    if (x >> i & 1)
        return solve2(a0, b1, x ^ (1 << i), i - 1) * solve2(a1, b0, x ^ (1 << i), i - 1);
    else
        return solve2(a0, b0, x, i - 1) + solve2(a1, b1, x, i - 1) + pw[a.size()] + pw[b.size()]
            - pw[a0.size()] - pw[a1.size()] - pw[b0.size()] - pw[b1.size()] + 1;
}

M solve(const vector<int> &a, int x, int i) {
    if (a.empty())
        return 1;
    if (i == -1)
        return pw[a.size()];
    vector<int> a0, a1;
    for (int y : a)
        (y >> i & 1 ? a1 : a0).push_back(y & ~(1 << i));
    if (x >> i & 1)
        return solve2(a0, a1, x ^ (1 << i), i - 1);
    else
        return solve(a0, x, i - 1) + solve(a1, x, i - 1) - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    pw[0] = 1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        pw[i+1] = pw[i] * 2;
    }
    cout << solve(a, x, 29) - 1 << "\n";

    return 0;
}