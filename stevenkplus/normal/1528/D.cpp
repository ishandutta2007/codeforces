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

const int inf = 1000 << 20;
struct node {
   int mn = inf, mx = -inf;
};
node operator+(node a, node b) {
   return {min(a.mn, b.mn), max(a.mx, b.mx)};
}

class LazySeg {
   int size;
   vector<node> data;
   vector<int> lazy;
   public:
   LazySeg(int _size) {
      size = 1;
      while (size < _size) size *= 2;
      data = vector<node>(size * 2);
      lazy = vector<int>(size * 2, -inf);
   }
   void down(int cur, int l, int r) {
      int cl = cur * 2, cr = cur * 2 + 1;
      if (lazy[cur] != -inf) {
         data[cl] = data[cr] = {lazy[cur], lazy[cur]};
         lazy[cl] = lazy[cr] = lazy[cur];
         lazy[cur] = -inf;
      }
   }
   // ASK
   node ask(int left, int right, int cur, int l, int r) {
      if (left <= l && r <= right) {
         return data[cur];
      } else if (left >= r || l >= right) {
         return {inf, -inf};
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         node ql = ask(left, right, cl, l, mid);
         node qr = ask(left, right, cr, mid, r);
         return ql + qr;
      }
   }
   node ask(int left, int right) {
      return ask(left, right, 1, 0, size);
   }
   // SET
   void set(int left, int right, int val, int cur, int l, int r) {
      if (left <= l && r <= right) {
         lazy[cur] = val;
         data[cur] = {val, val};
      } else if (left >= r || l >= right) {
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         set(left, right, val, cl, l, mid);
         set(left, right, val, cr, mid, r);
         data[cur] = data[cl] + data[cr];
      }
   }
   void set(int left, int right, int val) {
      set(left, right, val, 1, 0, size);
   }
};

// ============= Solution ============= //

int main() {
   int n, m;
   cin >> n >> m;
   vector<vector<pii>> ed(n);
   for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      ed[a].push_back(pii(b, c));
   }

   vector<vector<int>> ans(n, vector<int>(n));
   for (int cur = 0; cur < n; ++cur) {
      int t0 = inf;
      for (pii p: ed[cur]) t0 = min(t0, p.se);

      vector<vector<int>> layers(n);
      vector<int> dist(n, inf);
      vector<bool> vis(n);
      auto psh = [&](int i, int t) {
         if (dist[i] < t) return;
         if (t - t0 >= n) return;
         dist[i] = t;
         layers[t - t0].push_back(i);
      };
      for (pii p: ed[cur]) psh(p.fi, p.se);
      for (int i = 0; i < n; ++i) {
         for (int j: layers[i]) {
            if (vis[j]) continue;
            vis[j] = true;
            for (pii p: ed[j]) {
               psh((p.fi + i + t0) % n, i + t0 + p.se);
            }
            psh((j + 1) % n, i + t0 + 1);
         }
      }
      for (int i = 0; i < n; ++i) {
         ans[cur][i] = dist[i];
         ans[cur][cur] = 0;
      }
   }

   for (auto &v: ans) {
      for (int i: v) {
         cout << i << " ";
      }
      cout << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases