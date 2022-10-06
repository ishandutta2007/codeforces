// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

// scc https://ekzlib.netlify.app/external/spaghetti-source%252Falgorithm,graph%252Fstrongly_connected_component_tarjan.cc
#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

struct graph {
   int n;
   vector<vector<int>> adj;
   graph(int n) : n(n), adj(n) { }
   void add_edge(int src, int dst) {
      adj[src].push_back(dst);
   }

   vector<vector<int>> strongly_connected_components() {
      vector<int> open, id(n);
      vector<vector<int>> scc;
      int t = -n-1;
      auto argmin = [&](int u, int v) { return id[u] < id[v] ? u : v; };
      function<int(int)> dfs = [&](int u) {
         open.push_back(u);
         id[u] = t++;
         int w = u;
         for (int v: adj[u]) {
            if      (id[v] == 0) w = argmin(w, dfs(v));
            else if (id[v]  < 0) w = argmin(w, v);
         }
         if (w == u) {
            scc.push_back({});
            while (1) {
               int v = open.back();
               open.pop_back();
               id[v] = scc.size();
               scc.back().push_back(v);
               if (u == v) break;
            }
         }
         return w;
      };
      for (int u = 0; u < n; ++u) 
         if (id[u] == 0) dfs(u);
      return scc;
   }
};
// ============= Solution ============= //
int main() {
   int n, m;
   cin >> n >> m;
   auto id = [&](int i, int j) -> int {
      return i * m + j;
   };
   vector<string> inp(n);
   for (string &s: inp) cin >> s;
   vector<vector<int>> grid(n, vector<int>(m));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         grid[i][j] = inp[i][j] == '#';
      }
   }

   graph g(n * m + 1);
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (j + 1 < m && grid[i][j] && grid[i][j + 1]) {
            g.add_edge(id(i, j), id(i, j + 1));
            g.add_edge(id(i, j + 1), id(i, j));
         }
         if (i + 1 < n && grid[i][j] && grid[i + 1][j]) {
            g.add_edge(id(i, j), id(i + 1, j));
            g.add_edge(id(i + 1, j), id(i, j));
         }
         if (!grid[i][j]) {
            g.add_edge(n * m, id(i, j));
         }
      }
   }

   vector<int> last(m, -1);
   for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
         pp(j, i);
         if (!grid[i][j]) continue;
         if (last[j] != -1) {
            g.add_edge(id(i, j), id(last[j], j));
         }
         if (j + 1 < m && last[j + 1] != -1) {
            g.add_edge(id(i, j), id(last[j + 1], j + 1));
         }
         if (j > 0 && last[j - 1] != -1) {
            g.add_edge(id(i, j), id(last[j - 1], j - 1));
         }
      }
      for (int j = 0; j < m; ++j) {
         if (!grid[i][j]) continue;
         last[j] = i;
      }
   }

   vector<vector<int>> scc = g.strongly_connected_components();
   int numComponents = sz(scc);
   vector<int> compId(n * m + 1);
   for (int i = 0; i < numComponents; ++i) {
      for (int j: scc[i]) {
         compId[j] = i;
      }
   }
   pp(compId);
   vector<int> indeg(n * m + 1);
   for (int i = 0; i < n * m + 1; ++i) {
      for (int j: g.adj[i]) {
         if (compId[i] == compId[j]) continue;
         ++indeg[compId[j]];
      }
   }

   int ans = 0;
   for (int i = 0; i < numComponents; ++i) {
      if (indeg[i] == 0) {
         pp(i);
         pp(scc[i]);
         ++ans;
      }
   }
   cout << ans - 1 << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases