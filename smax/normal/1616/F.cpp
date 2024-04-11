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
using M = ModInt<3>;

// https://judge.yosupo.jp/submission/6280
// Is the difference really just my gauss elim code?
template <class T> int row_reduce(vector<vector<T>>& a, int lim = 1e9) {
  int n = a.size(), m = a[0].size(), rank = 0;
  for (int j = 0; j < min(m, lim); ++j) {
    for (int i = rank + 1; i < n; ++i) if (!(a[i][j] == 0)) {
      swap(a[rank], a[i]);
      break;
    }
    if (a[rank][j] == 0) continue;
    T inv = 1 / a[rank][j];
    for (auto&& e : a[rank]) e *= inv;
    for (int i = 0; i < n; ++i) if (i != rank and !(a[i][j] == 0))
      for (int k = m; k-- > j; ) a[i][k] -= a[rank][k] * a[i][j];
    if (++rank == n) break;
  }
  return rank;
}

template <class T>
vector<vector<T>> solve_linear(vector<vector<T>> a, vector<T> b) {
  int n = a.size(), m = a[0].size();
  for (int i = 0; i < n; ++i) a[i].push_back(b[i]);
  int rank = row_reduce(a, m);
  for (int i = rank; i < n; ++i) if (!(a[i][m] == 0)) return {};
  vector<vector<T>> res(1, vector<T>(m));
  vector<int> pivot(m, -1);
  for (int i = 0, j = 0; i < rank; ++i) {
    while (a[i][j] == 0) ++j;
    res[0][j] = a[i][m], pivot[j] = i;
  }
  for (int j = 0; j < m; ++j) if (pivot[j] == -1) {
    vector<T> x(m);
    x[j] = -1;
    for (int k = 0; k < j; ++k) if (pivot[k] != -1) x[k] = a[pivot[k]][j];
    res.push_back(x);
  }
  return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n, vector<int>(n, -1));
        vector<vector<M>> A;
        vector<M> B;
        for (int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            adj[a][b] = adj[b][a] = i;
            if (c != -1) {
                c--;
                A.emplace_back(m);
                B.push_back(c);
                A.back()[i] = 1;
            }
        }

        for (int u=0; u<n; u++)
            for (int v=u+1; v<n; v++)
                if (adj[u][v] != -1)
                    for (int w=v+1; w<n; w++)
                        if (adj[u][w] != -1 && adj[v][w] != -1) {
                            A.emplace_back(m);
                            B.push_back(0);
                            A.back()[adj[u][v]] = A.back()[adj[u][w]] = A.back()[adj[v][w]] = 1;
                        }

        if (A.empty()) {
            for (int i=0; i<m; i++)
                cout << "1 ";
            cout << "\n";
            continue;
        }
        vector<vector<M>> x = solve_linear(A, B);
        if (x.empty()) {
            cout << "-1\n";
        } else {
            for (M d : x[0])
                cout << d.v + 1 << " ";
            cout << "\n";
        }
    }

    return 0;
}