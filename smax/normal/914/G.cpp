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

// https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastSubsetTransform.h
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void FST(vector<M>& a, bool inv, bool op) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			M &u = a[j], &v = a[j + step]; tie(u, v) =
				op ? inv ? pair(v - u, u) : pair(v, u + v) // AND
				// inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
				: pair(u + v, u - v);                   // XOR /// include-line
		}
	}
	if (!op && inv) for (M& x : a) x /= sz(a); // XOR only /// include-line
}
vector<M> conv(vector<M> a, vector<M> b, bool op) {
	FST(a, 0, op); FST(b, 0, op);
	rep(i,0,sz(a)) a[i] *= b[i];
	FST(a, 1, op); return a;
}

// SOS DP, also known as Zeta transform, computes \sum_{S' \subseteq S} f(S') for all S in O(n * 2^n)
template<typename T>
vector<T> zetaTransform(int n, const vector<T> &f) {
    vector<T> dp = f;
    for (int i=0; i<n; i++)
        for (int mask=0; mask<1<<n; mask++)
            if (mask >> i & 1)
                dp[mask] += dp[mask ^ (1 << i)];
    return dp;
}

// Mobius transform (inclusion exclusion SOS), computes \sum_{S' \subseteq S} (-1)^{|S \setminus S'|} f(S') for all S in O(n * 2^n)
// also inverts the zeta transform (i.e. returns the input given an output)
template<typename T>
vector<T> mobiusTransform(int n, const vector<T> &f) {
    vector<T> dp = f;
    for (int i=0; i<n; i++)
        for (int mask=0; mask<1<<n; mask++)
            if (mask >> i & 1)
                dp[mask] -= dp[mask ^ (1 << i)];
    return dp;
}

// subset sum convolution, computes \sum_{S' \subseteq S} f(S') g(S \setminus S') for all S in O(n^2 * 2^n)
template<typename T>
vector<T> subsetConvolution(int n, const vector<T> &f, const vector<T> &g) {
    vector<vector<T>> fhat(n + 1, vector<T>(1 << n)), ghat(n + 1, vector<T>(1 << n)), h(n + 1, vector<T>(1 << n));
    for (int mask=0; mask<1<<n; mask++) {
        fhat[__builtin_popcount(mask)][mask] = f[mask];
        ghat[__builtin_popcount(mask)][mask] = g[mask];
    }
    for (int i=0; i<=n; i++) {
        fhat[i] = zetaTransform(n, fhat[i]);
        ghat[i] = zetaTransform(n, ghat[i]);
    }
    for (int mask=0; mask<1<<n; mask++)
        for (int i=0; i<=n; i++)
            for (int j=0; j<=i; j++)
                h[i][mask] += fhat[j][mask] * ghat[i-j][mask];
    for (int i=0; i<=n; i++)
        h[i] = mobiusTransform(n, h[i]);
    vector<T> ret(1 << n);
    for (int mask=0; mask<1<<n; mask++)
        ret[mask] = h[__builtin_popcount(mask)][mask];
    return ret;
}

const int LOG = 17;

M fib[1 << LOG];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fib[1] = 1;
    for (int i=2; i<1<<LOG; i++)
        fib[i] = fib[i-1] + fib[i-2];

    int n;
    cin >> n;
    vector<M> f(1 << LOG);
    for (int i=0; i<n; i++) {
        int s;
        cin >> s;
        f[s] += 1;
    }

    vector<M> ab = subsetConvolution(LOG, f, f), c = f, de = conv(f, f, false);
    for (int mask=0; mask<1<<LOG; mask++) {
        ab[mask] *= fib[mask];
        c[mask] *= fib[mask];
        de[mask] *= fib[mask];
    }

    vector<M> fin = conv(conv(ab, c, true), de, true);
    M ret = 0;
    for (int i=0; i<LOG; i++)
        ret += fin[1 << i];
    cout << ret << "\n";

    return 0;
}