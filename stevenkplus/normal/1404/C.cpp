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
// =========== Book ============ //

const int inf = 1000 << 20;

class LazySeg {
   int size;
   vector<pii> data;
   vector<int> lazy;
   public:
   LazySeg(int _size) {
      size = 1;
      while (size < _size) size *= 2;
      data = vector<pii>(size * 2);
      lazy = vector<int>(size * 2);
   }
   // BUILD
   void build(vector<pii> &ar, int cur, int l, int r) {
      if (l + 1 == r) {
         data[cur] = ar[l];
      } else {
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         build(ar, cl, l, mid);
         build(ar, cr, mid, r);
         data[cur] = min(data[cl], data[cr]);
      }
   }
   void build(vector<pii> &ar) {
      build(ar, 1, 0, size);
   }
   void down(int cur) {
      int cl = cur * 2, cr = cur * 2 + 1;
      int diff = lazy[cur];
      data[cl].fi += diff;
      data[cr].fi += diff;
      lazy[cl] += lazy[cur];
      lazy[cr] += lazy[cur];
      lazy[cur] = 0;
   }
   // ASK
   pii ask(int left, int right, int cur, int l, int r) {
      if (left <= l && r <= right) {
         return data[cur];
      } else if (left >= r || l >= right) {
         return pii(inf, -1);
      } else {
         down(cur);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         pii ql = ask(left, right, cl, l, mid);
         pii qr = ask(left, right, cr, mid, r);
         return min(ql, qr);
      }
   }
   pii ask(int left, int right) {
      return ask(left, right, 1, 0, size);
   }
   // ADD
   void add(int left, int right, int val, int cur, int l, int r) {
      if (left <= l && r <= right) {
         lazy[cur] += val;
         data[cur].fi += val;
      } else if (left >= r || l >= right) {
      } else {
         down(cur);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         add(left, right, val, cl, l, mid);
         add(left, right, val, cr, mid, r);
         data[cur] = min(data[cl], data[cr]);
      }
   }
   // SET
   void set(int idx, int val, int cur, int l, int r) {
      if (idx < l || idx >= r) {
         return;
      }
      if (l + 1 == r) {
         data[cur].fi = val;
      } else {
         down(cur);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         set(idx, val, cl, l, mid);
         set(idx, val, cr, mid, r);
         data[cur] = min(data[cl], data[cr]);
      }
   }
   void add(int left, int right, int val) {
      add(left, right, val, 1, 0, size);
   }
   void set(int idx, int val) {
      set(idx, val, 1, 0, size);
   }
};


// ============= Solution ============= //
int main() {
   int n, q;
   cin >> n >> q;
   vector<int> v(n);
   for (int &i: v) cin >> i;
   int size = 1;
   while (size < n) size *= 2;
   LazySeg seg(size);
   vector<pii> data(size);
   for (int i = 0; i < n; ++i) {
      data[i].fi = i + 1 - v[i];
      data[i].se = i;
      if (data[i].fi < 0) data[i].fi = inf;
   }
   seg.build(data);
   pp("built", data);

   vector<int> x(q), y(q), ans(q);
   vector<vector<int>> qs(n);
   for (int i = 0; i < q; ++i) {
      cin >> x[i] >> y[i];
      qs[x[i]].push_back(i);
   }

   pp("qs", qs);

   vector<int> bit(n + 1);
   // ar[idx] += 1
   auto inc = [&](int idx) -> void {
      ++idx;
      while (idx <= n) {
         bit[idx] += 1;
         idx += idx & -idx;
      }
   };

   // sum(ar[0]...ar[idx])
   auto ask = [&](int idx) -> int {
      ++idx;
      int res = 0;
      while (idx) {
         res += bit[idx];
         idx -= idx & -idx;
      }
      return res;
   };

   for (int i = n - 1; i >= 0; --i) {
      pp("On", i);
      while (true) {
         pii p = seg.ask(i, n);
         pp("Min is", p);
         if (p.fi <= 0) {
            int cur = p.se;
            inc(cur);
            seg.set(cur, inf);
            seg.add(cur, n, -1);
         } else {
            break;
         }
      }
      for (int qi: qs[i]) {
         ans[qi] = ask(n - y[qi] - 1);
      }
   }
   for (int i: ans) {
      cout << i << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases