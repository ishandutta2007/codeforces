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

// Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/various/FastMod.h

typedef unsigned long long ull;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(-1ULL / b) {}
	ull reduce(ull a) { // a % b + (0 or b)
		return a - (ull)((__uint128_t(m) * a) >> 64) * b;
	}
};

FastMod fm(1);

int MOD;
struct ModInt {
    long long v;
    ModInt(long long _v = 0) {v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD;}
    ModInt& operator += (const ModInt &other) {v += other.v; if (v >= MOD) v -= MOD; return *this;}
    ModInt& operator -= (const ModInt &other) {v -= other.v; if (v < 0) v += MOD; return *this;}
    ModInt& operator *= (const ModInt &other) {
        // v = v * other.v % MOD; return *this;
        v = fm.reduce(v * other.v);
        return *this;
    }
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

const int MAX = 124750;

ModInt dp[2 * MAX + 1], ndp[2 * MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> MOD;
    fm = FastMod(MOD);

    vector<ModInt> ways(n);
    ways[0] = 1;
    for (int i=0; i<n-1; i++)
        ways[i+1] = (n - i) * ways[i];

    auto query = [&] (int l, int r) -> ModInt {
        if (l < 0 || l > r) return 0;
        return dp[r] - (l > 0 ? dp[l-1] : 0);
    };

    ModInt ret = 0;
    dp[MAX] = 1;
    for (int i=0; i<n; i++) {
        for (int j=1; j<=2*MAX; j++)
            dp[j] += dp[j-1];
        for (int a=0; a<i+1; a++)
            for (int b=a+1; b<i+1; b++)
                ret += ways[n-i-1] * query(b - a + 1 + MAX, 2 * MAX);
        for (int j=0; j<=2*MAX; j++)
            ndp[j] = (j > 0 ? ndp[j-1] : 0) + query(j, min(j + i, 2 * MAX)) - query(j - 1, j - 1) * (i + 1) - query(max(j - i - 1, 0), j - 2) + query(j - 1, j - 1) * i;
        memcpy(dp, ndp, sizeof(ndp));
    }
    cout << ret << "\n";

    return 0;
}