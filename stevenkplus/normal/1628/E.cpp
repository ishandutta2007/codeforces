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
//
// Key insight: since we are taking max weight of edges, paths can be *concatenated* -- so we take a tour
// Equivalent formulation: We are asking for max weight of spanning tree of a set of nodes, so we can take max weight of any tour since the tour will be the spanning tree after dedup'ing edges
//
// Max danger of path from x to any "on" node in tree == Max edge weight along any path from x that "tours" all on nodes in tree
// Pick tour that visits all "on" nodes in increasing order of idx
// For each node track whether it's on, and if so, the weight of the path from it to its successor (next node that is on)
// weight is 0 if no successor
//
// Maintain a segtree over this data, aggregating values by taking max, and also support querying min & max indices of on nodes.
// Keep lazy flag for intervals that are either all "stupidly on" or all off
//
// A node i is "stupidly on" if it is on and its successor is i+1 -- intervals that are entirely stupidly on can be precomputed (seg2 in code)
//
// Queries:
// t=1 -> set [l, r - 1] to "stupidly on", and set r to on. update r's value and predecessor(l)
// t=2 -> set [l, r] to off, update predecessor(l)'s value
// t=3 -> query [0, n) to find the weight of tour connecting all "on" nodes. max it with distance from x to any "on" node. return -1 if no "on" nodes or ans is 0 (i.e. only open store is x)

struct node {
   int min, max, val, size;
};
node operator+(node a, node b) {
   if (a.size == 0) return b;
   if (b.size == 0) return a;
   return { a.min, b.max, max(a.val, b.val), a.size + b.size };
}

int main() {
   int n, q;
   cin >> n >> q;
   vector<vector<pii>> ed(n);
   for (int i = 0; i < n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a, --b;
      ed[a].push_back(pii(b, c));
      ed[b].push_back(pii(a, c));
   }
   vector<int> par(n), depth(n), parwt(n);
   auto dfs = yc([&](auto rec, int cur) -> void {
      for (pii nxt: ed[cur]) {
         if (nxt.fi == par[cur]) continue;
         par[nxt.fi] = cur;
         parwt[nxt.fi] = nxt.se;
         depth[nxt.fi] = depth[cur] + 1;
         rec(nxt.fi);
      }
   });
   dfs(0);
   vector<vector<int>> jump(20, vector<int>(n)), jumpwt(20, vector<int>(n));
   for (int i = 0; i < n; ++i) {
      jump[0][i] = par[i];
      jumpwt[0][i] = parwt[i];
   }
   for (int i = 0; i + 1 < 20; ++i) {
      for (int j = 0; j < n; ++j) {
         jump[i + 1][j] = jump[i][jump[i][j]];
         jumpwt[i + 1][j] = max(jumpwt[i][j], jumpwt[i][jump[i][j]]);
      }
   }
   auto getPath = [&](int a, int b) -> int {
      if (depth[a] < depth[b]) swap(a, b);
      int c = depth[a] - depth[b];
      int res = 0;
      for (int i = 0; i < 20; ++i) {
         if ((c >> i) & 1) {
            res = max(res, jumpwt[i][a]);
            a = jump[i][a];
         }
      }
      if (a == b) return res;
      for (int i = 19; i >= 0; --i) {
         if (jump[i][a] != jump[i][b]) {
            res = max(res, jumpwt[i][a]);
            res = max(res, jumpwt[i][b]);
            a = jump[i][a];
            b = jump[i][b];
         }
      }
      res = max(res, jumpwt[0][a]);
      res = max(res, jumpwt[0][b]);
      return res;
   };

   int size = 1;
   while (size < n) size *= 2;
   vector<node> seg(size * 2);
   vector<bool> lazy(size * 2);
   vector<node> seg2(size * 2);
   for (int i = 0; i < n; ++i) {
      seg2[i + size] = {
         i, i, i + 1 < n ? getPath(i, i + 1) : 0, 1
      };
   }
   for (int i = size - 1; i; --i) {
      seg2[i] = seg2[i * 2] + seg2[i * 2 + 1];
   }

   auto down = [&](int cur) {
      if (cur >= size || !lazy[cur]) return;
      lazy[cur] = false;
      lazy[cur * 2] = lazy[cur * 2 + 1] = true;
      if (seg[cur].size) {
         seg[cur * 2] = seg2[cur * 2];
         seg[cur * 2 + 1] = seg2[cur * 2 + 1];
      } else {
         seg[cur * 2] = {0, 0, 0, 0};
         seg[cur * 2 + 1] = {0, 0, 0, 0};
      }
   };


   auto ask = yc([&](auto rec, int left, int right, int cur, int l, int r) -> node {
      if (left >= r || l >= right) return {0, 0, 0, 0};
      if (left <= l && r <= right) {
         return seg[cur];
      } else {
         down(cur);
         int mid = (l + r) / 2;
         return rec(left, right, cur * 2, l, mid) + rec(left, right, cur * 2 + 1, mid, r);
      }
   });
   auto set = yc([&](auto rec, int left, int right, bool on, int cur, int l, int r) {
      if (left >= r || l >= right) return;
      if (left <= l && r <= right) {
         if (on) {
            lazy[cur] = true;
            seg[cur] = seg2[cur];
         } else {
            lazy[cur] = true;
            seg[cur] = {0, 0, 0, 0};
         }
      } else {
         down(cur);
         int mid = (l + r) / 2;
         rec(left, right, on, cur * 2, l, mid);
         rec(left, right, on, cur * 2 + 1, mid, r);
         seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
      }
   });
   auto upd = yc([&](auto rec, int x, int val, int cur, int l, int r) {
      if (x >= r || l > x) return;
      if (x == l && r == l + 1) {
         seg[cur] = {
            x, x, val, 1,
         };
      } else {
         down(cur);
         int mid = (l + r) / 2;
         rec(x, val, cur * 2, l, mid);
         rec(x, val, cur * 2 + 1, mid, r);
         seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
      }
   });

   while (q--) {
      int t;
      cin >> t;
      if (t == 1 || t == 2) {
         int l, r;
         cin >> l >> r; --l, --r;
         node nleft = ask(0, l, 1, 0, size);
         node nright = ask(r + 1, n, 1, 0, size);
         if (t == 1) {
            set(l, r, true, 1, 0, size);
            upd(r, nright.size ? getPath(r, nright.min) : 0, 1, 0, size);
            if (nleft.size) {
               upd(nleft.max, getPath(l, nleft.max), 1, 0, size);
            }
         } else {
            set(l, r + 1, false, 1, 0, size);
            if (nleft.size) {
               upd(nleft.max, nright.size ? getPath(nright.min, nleft.max) : 0, 1, 0, size);
            }
         }
      } else {
         int x;
         cin >> x; --x;
         node nn = ask(0, n, 1, 0, size);
         if (!nn.size) cout << "-1\n";
         else {
            int ans1 = getPath(x, nn.min);
            int ans2 = nn.val;
            int ans = max(ans1, ans2);
            if (!ans) ans = -1;
            cout << ans << "\n";
         }
      }
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases