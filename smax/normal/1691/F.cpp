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

const int MAX = 2e5 + 5;

M fact[MAX], inv[MAX];

M choose(int n, int k) {
    if (k < 0 || n < k) return 0;
    return fact[n] * inv[k] * inv[n-k];
}

void preprocess() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++)
        fact[i] = fact[i-1] * i;
    inv[MAX-1] = inverse(fact[MAX-1]);
    for (int i=MAX-2; i>=0; i--)
        inv[i] = inv[i+1] * (i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preprocess();

    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> sz(n);
    vector<M> ways(n), dp(n);

    auto dfs1 = [&] (auto &self, int u, int p) -> void {
        sz[u] = 1;
        for (int v : adj[u])
            if (v != p) {
                self(self, v, u);
                sz[u] += sz[v];
                dp[u] += dp[v];
                ways[u] -= choose(sz[v], k);
            }
        ways[u] += choose(sz[u], k);
        dp[u] += sz[u] * ways[u];
    };

    auto dfs2 = [&] (auto &self, int u, int p) -> M {
        M ret = dp[u];
        for (int v : adj[u])
            if (v != p) {
                // update u
                dp[u] -= sz[u] * ways[u] + dp[v];
                ways[u] -= choose(sz[u], k) - choose(sz[v], k);
                sz[u] -= sz[v];
                ways[u] += choose(sz[u], k);
                dp[u] += sz[u] * ways[u];
                // update v
                dp[v] -= sz[v] * ways[v];
                ways[v] -= choose(sz[v], k);
                sz[v] += sz[u];
                ways[v] += choose(sz[v], k) - choose(sz[u], k);
                dp[v] += sz[v] * ways[v] + dp[u];
                // go
                ret += self(self, v, u);
                // rollback v
                dp[v] -= sz[v] * ways[v] + dp[u];
                ways[v] -= choose(sz[v], k) - choose(sz[u], k);
                sz[v] -= sz[u];
                ways[v] += choose(sz[v], k);
                dp[v] += sz[v] * ways[v];
                // rollback u
                dp[u] -= sz[u] * ways[u];
                ways[u] -= choose(sz[u], k);
                sz[u] += sz[v];
                ways[u] += choose(sz[u], k) - choose(sz[v], k);
                dp[u] += sz[u] * ways[u] + dp[v];
            }
        return ret;
    };

    dfs1(dfs1, 0, -1);
    cout << dfs2(dfs2, 0, -1) << "\n";

    return 0;
}