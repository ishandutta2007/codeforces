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

template<int SZ>
struct DSU {
    int par[SZ], sz[SZ];

    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int findRoot(int u) {
        if (u != par[u])
            par[u] = findRoot(par[u]);
        return par[u];
    }

    bool unite(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int numEdges[1505];
vector<M> poly[1505];
DSU<1505> ds;

vector<M> multiply(const vector<M> &a, const vector<M> &b) {
    vector<M> ret((int) a.size() + (int) b.size() - 1);
    for (int i=0; i<(int)a.size(); i++)
        for (int j=0; j<(int)b.size(); j++)
            ret[i+j] += a[i] * b[j];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<tuple<int, int, int>> edges;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            int a;
            cin >> a;
            if (i < j)
                edges.emplace_back(a, i, j);
        }

    sort(edges.begin(), edges.end());
    ds.init(n);
    for (int i=0; i<n; i++)
        poly[i] = {0, 1};
    for (auto [w, u, v] : edges) {
        u = ds.findRoot(u);
        v = ds.findRoot(v);
        if (ds.unite(u, v)) {
            int z = ds.findRoot(u);
            poly[z] = multiply(poly[u], poly[v]);
            numEdges[z] = numEdges[u] + numEdges[v];
        }
        int z = ds.findRoot(u);
        numEdges[z]++;
        if (numEdges[z] == ds.sz[z] * (ds.sz[z] - 1) / 2)
            poly[z][1] += 1;
    }

    int z = ds.findRoot(0);
    for (int i=1; i<=n; i++)
        cout << poly[z][i] << " ";
    cout << "\n";

    return 0;
}