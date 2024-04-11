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
   int T;
   cin >> T;
   while (T--) {
      int n;
      cin >> n;
      vector<int> par1(n), par2(n);
      for (int i = 1; i < n; ++i) cin >> par1[i], --par1[i];
      for (int i = 1; i < n; ++i) cin >> par2[i], --par2[i];
      vector<vector<int>> ed1(n);
      vector<vector<int>> ed2(n);
      for (int i = 1; i < n; ++i) {
         ed1[par1[i]].push_back(i);
         ed2[par2[i]].push_back(i);
      }
      vector<int> left(n), right(n);
      int cnt = 0;
      auto dfs2 = yc([&](auto rec, int cur) -> void {
         left[cur] = cnt++;
         for (int nxt: ed2[cur]) {
            rec(nxt);
         }
         right[cur] = cnt;
      });
      dfs2(0);

      LazySeg seg(n + 1);
      seg.set(0, n, -1);

      int ans = 0;
      auto dfs1 = yc([&](auto rec, int cur, int val) -> void {
         node c = seg.ask(left[cur], right[cur]);
         pp(cur, c.mn, c.mx);
         if (c.mn == c.mx) {
            if (c.mn == -1) {
               ++val;
            } else {
               seg.set(left[c.mn], right[c.mx], -1);
            }
            seg.set(left[cur], right[cur], cur);
         }
         ans = max(ans, val);
         for (int nxt: ed1[cur]) {
            rec(nxt, val);
         }
         if (c.mn == c.mx) {
            if (c.mn == -1) {
               seg.set(left[cur], right[cur], -1);
            } else {
               seg.set(left[c.mn], right[c.mx], c.mn);
            }
         }
      });
      dfs1(0, 0);
      cout << ans << "\n";
   };
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases