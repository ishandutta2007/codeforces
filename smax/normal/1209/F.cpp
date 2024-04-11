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
typedef ModInt<1000000007> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int inN = n;

    vector<vector<vector<int>>> adj(n, vector<vector<int>>(10));

    auto addEdge = [&] (int u, int v, int w) -> void {
        if (u >= (int) adj.size() || v >= (int) adj.size())
            adj.emplace_back(10);
        adj[u][w].push_back(v);
    };

    auto decompose = [&] (int x) -> vector<int> {
        vector<int> ret;
        while (x > 0) {
            ret.push_back(x % 10);
            x /= 10;
        }
        return {ret.rbegin(), ret.rend()};
    };

    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        vector<int> digits = decompose(i);
        if (digits.size() == 1) {
            addEdge(x, y, digits[0]);
            addEdge(y, x, digits[0]);
        } else {
            for (int rep=0; rep<2; rep++) {
                addEdge(x, n, digits[0]);
                for (int j=1; j<(int)digits.size()-1; j++) {
                    addEdge(n, n + 1, digits[j]);
                    n++;
                }
                addEdge(n, y, digits.back());
                n++;
                swap(x, y);
            }
        }
    }

    vector<bool> vis(n);
    vector<M> ret(n);
    vector<vector<int>> q(1);
    vis[0] = true;
    q[0].push_back(0);
    for (int i=0; i<(int)q.size(); i++)
        for (int d=0; d<10; d++) {
            bool f = true;
            for (int u : q[i])
                for (int v : adj[u][d])
                    if (!vis[v]) {
                        if (f) {
                            q.emplace_back();
                            f = false;
                        }
                        vis[v] = true;
                        ret[v] = ret[u] * 10 + d;
                        q.back().push_back(v);
                    }
        }

    for (int u=1; u<inN; u++)
        cout << ret[u] << "\n";

    return 0;
}