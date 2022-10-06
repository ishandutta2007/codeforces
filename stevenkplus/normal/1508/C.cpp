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

// ============= Solution ============= //
int main() { // dobby is a free elf
   int n, m;
   cin >> n >> m;
   vector<pair<int, pii>> edges(m);
   vector<vector<int>> ed(n);
   for (auto &e: edges) {
      cin >> e.se.fi >> e.se.se >> e.fi;
      --e.se.fi, --e.se.se;
      ed[e.se.fi].push_back(e.se.se);
      ed[e.se.se].push_back(e.se.fi);
   }
   vector<int> par(n);
   vector<int> siz(n);
   vector<ll> sums(n);
   for (int i = 0; i < n; ++i) {
      par[i] = i;
      siz[i] = 1;
      sums[i] = i;
   }
   vector<int> rts = par;
   auto find = yc([&](auto rec, int x) -> int {
      if (par[x] == x) return x;
      return par[x] = rec(par[x]);
   });
   vector<pair<pii, int>> ed2;
   for (int i = 0; i < n; ++i) {
      vector<int> nrts;
      map<int, int> hits;
      map<int, ll> sum;
      for (int j: ed[i]) {
         ++hits[find(j)];
         sum[find(j)] += j;
      }
      for (int r: rts) {
         if (par[r] != r) continue;
         if (r != find(i) && siz[r] > hits[r]) {
            siz[find(i)] += siz[r];
            sums[find(i)] += sums[r];
            ed2.emplace_back(pii(i, sums[r] - sum[r]), 0);
            par[r] = i;
         } else {
            nrts.push_back(r);
         }
      }
      rts = nrts;
   }

   int cnt = 0;
   for (int i = 0; i < n; ++i) {
      if (par[i] == i) ++cnt;
   }
   ll tot_zeros = 1LL * n * (n - 1) / 2 - m;
   int mn = 0;
   for (auto e: edges) mn ^= e.fi;
   if (tot_zeros > n - cnt) {
      mn = 0;
   }
   ll ans = 0;
   sort(edges.begin(), edges.end());
   set<pii> take;
   for (auto e: edges) {
      if (find(e.se.fi) != find(e.se.se)) {
         par[find(e.se.fi)] = find(e.se.se);
         take.insert(e.se);
         ed2.emplace_back(e.se, 1);
         ans += e.fi;
      }
   }

   if (mn > 0) {
      for (int i = 0; i < n; ++i) {
         ed[i].clear();
         par[i] = i;
      }
      vector<vector<int>> edw(n);
      vector<vector<int>> par(20, vector<int>(n));
      vector<int> depth(n);
      vector<int> numZerosOnPath(n);
      pp(ed2);
      for (auto e: ed2) {
         ed[e.fi.fi].push_back(e.fi.se);
         edw[e.fi.fi].push_back(e.se);
         ed[e.fi.se].push_back(e.fi.fi);
         edw[e.fi.se].push_back(e.se);
      }
      auto dfs = yc([&](auto rec, int cur) -> void {
         pp(cur);
         for (int i = 0; i < sz(ed[cur]); ++i) {
            int nxt = ed[cur][i];
            if (nxt == par[0][cur]) continue;
            numZerosOnPath[nxt] = numZerosOnPath[cur] + 1 - edw[cur][i];
            par[0][nxt] = cur;
            depth[nxt] = depth[cur] + 1;
            rec(nxt);
         }
      });
      dfs(0);
      for (int i = 0; i + 1 < 20; ++i) {
         for (int j = 0; j < n; ++j) {
            par[i + 1][j] = par[i][par[i][j]];
         }
      }
      auto lca = [&](int a, int b) -> int {
         if (depth[a] < depth[b]) swap(depth[a], depth[b]);
         int diff = depth[a] - depth[b];
         for (int i = 0; i < 20; ++i) {
            if ((diff >> i) & 1) {
               a = par[i][a];
            }
         }
         for (int i = 19; i >= 0; --i) {
            if (par[i][a] != par[i][b]) {
               a = par[i][a];
               b = par[i][b];
            }
         }
         return par[0][a];
      };
               pp(mn);
      for (auto e: edges) {
         if (take.find(e.se) == take.end()) {
            int k = lca(e.se.fi, e.se.se);
            if (numZerosOnPath[e.se.fi] + numZerosOnPath[e.se.se] - 2 * numZerosOnPath[k] > 0) {
               mn = min(mn, e.fi);
            }
         }
      }
               pp(mn);
   }
   ans += mn;
   cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases