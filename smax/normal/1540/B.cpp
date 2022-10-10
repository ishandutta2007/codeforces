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
typedef ModInt<1000000007> M;

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

struct LCA {
    vector<int> in, out, depth, path, ret;
    vector<vector<int>> adj;
    RMQ<int> rmq;

    LCA(int n) : in(n), out(n), depth(n), adj(n), rmq({}) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = 0) {
        dfs(r, -1);
        rmq = RMQ<int>(ret);
    }

    void dfs(int u, int p) {
        in[u] = (int) path.size();
        path.push_back(u);
        ret.push_back(in[u]);
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
                path.push_back(u);
                ret.push_back(in[u]);
            }
        out[u] = (int) path.size();
    }

    int lca(int u, int v) {
        if (in[u] > in[v])
            swap(u, v);
        return path[rmq.query(in[u], in[v])];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool anc(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    M div2 = inverse(M(2));
    vector<vector<M>> dp(n + 1, vector<M>(n + 1));
    for (int i=1; i<=n; i++)
        dp[i][0] = 1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) * div2;

    M ret = 0;
    for (int r=0; r<n; r++) {
        LCA lca(n);
        lca.adj = adj;
        lca.init(r);
        for (int u=0; u<n; u++)
            for (int v=u+1; v<n; v++) {
                if (lca.anc(v, u)) {
                    ret += 1;
                } else if (!lca.anc(u, v)) {
                    int w = lca.lca(u, v), du = lca.depth[u] - lca.depth[w], dv = lca.depth[v] - lca.depth[w];
                    ret += dp[du][dv];
                }
            }
    }
    cout << ret / n << "\n";

    return 0;
}