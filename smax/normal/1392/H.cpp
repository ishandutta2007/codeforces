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
typedef ModInt<998244353> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // Expected time of a single iteration
    // Probability we draw a card before any joker: 1 / (m + 1)
    M ti = M(n) / (m + 1) + 1;

    // Expected number of iterations
    // We have k remaining cards that we need in S
    // Probability the first card we draw that changes something (out of the k missing + m jokers) is a joker: m / (m + k)
    // Expected number of iterations with a certain value of k: I_k
    // I_k = m / (m + k) * (I_k + 1) + k / (m + k) * I_{k-1}
    // Note: No +1 after I_{k-1} because if we draw a non-joker, we're still on the same iteration
    // I_k = m / (m + k) * I_k + m / (m + k) + k / (m + k) * I_{k-1}
    // k / (m + k) * I_k = m / (m + k) + k / (m + k) * I_{k-1}
    // k * I_k = m + k * I_{k-1}
    // I_k = m / k + I_{k-1}
    // Another way of deriving it: Expected number of iterations until we transition from I_k to I_{k-1}
    // I_k = 1 + m / (m + k) * I_k
    // k / (m + k) * I_k = 1
    // I_k = (m + k) / k = m / k + 1
    // And then we get rid of the +1 because I_{k-1} is also part of that same final iteration
    // k = 1: I_1 = 1 + m / (m + 1) * I_1
    // 1 / (m + 1) * I_1 = 1
    // I_1 = m + 1
    // I_2 = m / 2 + m + 1
    // I_3 = m / 3 + m / 2 + m + 1
    // I_4 = m / 4 + m / 3 + m / 2 + m + 1
    // ...
    // I_k = m * (1 / k + 1 / (k - 1) + ... + 1 / 1) + 1
    M cnt = 0;
    for (int i=1; i<=n; i++)
        cnt += inverse(M(i));
    cnt = cnt * m + 1;

    cout << ti * cnt << "\n";

    return 0;
}