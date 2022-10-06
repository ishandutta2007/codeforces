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
#define sub_to_errichto main
// =========== Book ============ //
// https://github.com/kth-competitive-programming/kactl/blob/master/content/graph/Dinic.h
namespace kactl {
   typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
   bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
      if (A[a] != L) return 0;
      A[a] = -1;
      for (int b : g[a]) if (B[b] == L + 1) {
         B[b] = 0;
         if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
            return btoa[b] = a, 1;
      }
      return 0;
   }

   int hopcroftKarp(vector<vi>& g, vi& btoa) {
      int res = 0;
      vi A(g.size()), B(btoa.size()), cur, next;
      for (;;) {
         fill(all(A), 0);
         fill(all(B), 0);
         /// Find the starting nodes for BFS (i.e. layer 0).
         cur.clear();
         for (int a : btoa) if(a != -1) A[a] = -1;
         rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
         /// Find all layers using bfs.
         for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for (int a : cur) for (int b : g[a]) {
               if (btoa[b] == -1) {
                  B[b] = lay;
                  islast = 1;
               }
               else if (btoa[b] != a && !B[b]) {
                  B[b] = lay;
                  next.push_back(btoa[b]);
               }
            }
            if (islast) break;
            if (next.empty()) return res;
            for (int a : next) A[a] = lay;
            cur.swap(next);
         }
         /// Use DFS to scan for augmenting paths.
         rep(a,0,sz(g))
            res += dfs(a, 0, g, btoa, A, B);
      }
   }
   struct Dinic {
      struct Edge {
         int to, rev;
         ll c, oc;
         ll flow() { return max(oc - c, 0LL); } // if you need flows
      };
      vi lvl, ptr, q;
      vector<vector<Edge>> adj;
      Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
      void addEdge(int a, int b, ll c, int rcap = 0) {
         adj[a].push_back({b, sz(adj[b]), c, c});
         adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
      }
      ll dfs(int v, int t, ll f) {
         if (v == t || !f) return f;
         for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
               if (ll p = dfs(e.to, t, min(f, e.c))) {
                  e.c -= p, adj[e.to][e.rev].c += p;
                  return p;
               }
         }
         return 0;
      }
      ll calc(int s, int t) {
         ll flow = 0; q[0] = s;
         rep(L,0,31) do { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
               int v = q[qi++];
               for (Edge e : adj[v])
                  if (!lvl[e.to] && e.c >> (30 - L))
                     q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
         } while (lvl[t]);
         return flow;
      }
      bool leftOfMinCut(int a) { return lvl[a] != 0; }
   };
}
// ============= Solution ============= //
int sub_to_errichto() {
   int n, m;
   cin >> n >> m;
   vector<pair<int, pii>> edges(m);
   for (int i = 0; i < m; ++i) {
      cin >> edges[i].se.fi >> edges[i].se.se >> edges[i].fi;
      --edges[i].se.fi, --edges[i].se.se;
   }
   sort(edges.begin(), edges.end());

   auto can = [&](int len) -> bool {
      vector<vector<int>> graph(n);
      for (int i = 0; i < len; ++i) {
         graph[edges[i].se.fi].push_back(edges[i].se.se);
      }
      vector<int> rev(n, -1);
      int matches = kactl::hopcroftKarp(graph, rev);
      pp(graph, matches, rev);
      return matches == n;

      // kactl::Dinic dinic(2 * n + 2);
      // for (int i = 0; i < len; ++i) {
         // dinic.addEdge(edges[i].se.fi, n + edges[i].se.se, 1);
      // }
      // for (int i = 0; i < n; ++i) {
         // dinic.addEdge(2 * n, i, 1);
         // dinic.addEdge(n + i, 2 * n + 1, 1);
      // }
      // int flow = dinic.calc(2 * n, 2 * n + 1);
      // return flow == n;

      // vector<vector<int>> ed(n);
      // vector<int> from(n, -1);
      // vector<bool> vis(n);
      // vector<int> v;
      // v.reserve(n);
      // auto go = yc([&](auto go, int cur) -> bool {
      // if (cur == -1) return true;
      // if (vis[cur]) return false;
      // vis[cur] = true;
      // v.push_back(cur);
      // for (int i: ed[cur]) {
      // if (go(from[i])) {
      // from[i] = cur;
      // return true;
      // }
      // }
      // return false;
      // });

      // for (int i = 0; i < n; ++i) {
      // if (!go(i)) return false;
      // for (int cur: v) {
      // vis[cur] = false;
      // }
      // v.clear();
      // }
      // return true;
   };

   int lo = 0, hi = m;
   while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (can(mid + 1)) {
         hi = mid;
      } else {
         lo = mid + 1;
      }
   }

   int ans;
   if (lo == m) {
      ans = -1;
   } else {
      ans = edges[lo].fi;
   }
   cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases