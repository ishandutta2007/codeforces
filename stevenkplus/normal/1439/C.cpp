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

class LazySeg {
   int size;
   vector<ll> min;
   vector<ll> max;
   vector<ll> sum;
   public:
   LazySeg(int _size) {
      size = 1;
      while (size < _size) size *= 2;
      min = vector<ll>(size * 2);
      max = vector<ll>(size * 2);
      sum = vector<ll>(size * 2);
   }
   // BUILD
   void build(vector<ll> &ar, int cur, int l, int r) {
      if (l + 1 == r) {
         ll val = l < sz(ar) ? ar[l] : 0;
         sum[cur] = val;
         min[cur] = max[cur] = val;
      } else {
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         build(ar, cl, l, mid);
         build(ar, cr, mid, r);
         sum[cur] = sum[cl] + sum[cr];
         max[cur] = max[cl];
         min[cur] = min[cr];
      }
   }
   void build(vector<ll> &ar) {
      build(ar, 1, 0, size);
   }
   void down(int cur, int l, int r) {
      int cl = cur * 2, cr = cur * 2 + 1;
      if (min[cur] == max[cur]) {
         min[cl] = min[cr] = min[cur];
         max[cl] = max[cr] = max[cur];
         sum[cl] = sum[cr] = sum[cur] / 2;
      }
   }
   // SETMAX
   void setmax(int left, int right, ll val, int cur, int l, int r) {
      if (min[cur] >= val) return;
      if (left <= l && r <= right && max[cur] <= val) {
         min[cur] = max[cur] = val;
         sum[cur] = val * (r - l);
      } else if (left >= r || l >= right) {
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         setmax(left, right, val, cl, l, mid);
         setmax(left, right, val, cr, mid, r);
         sum[cur] = sum[cl] + sum[cr];
         min[cur] = min[cr];
         max[cur] = max[cl];
      }
   }
   void setmax(int left, int right, ll val) {
      setmax(left, right, val, 1, 0, size);
   }
   // ASK
   ll ask(int left, int right, int cur, int l, int r) {
      if (left <= l && r <= right) {
         return sum[cur];
      } else if (left >= r || l >= right) {
         return 0;
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         ll ql = ask(left, right, cl, l, mid);
         ll qr = ask(left, right, cr, mid, r);
         return ql + qr;
      }
   }
   ll ask(int left, int right) {
      return ask(left, right, 1, 0, size);
   }

   // FIND
   int find(ll val, int cur, int l, int r) {
      if (l + 1 == r) {
         if (sum[cur] <= val) {
            return r;
         } else {
            return l;
         }
      }
      down(cur, l, r);
      int mid = (l + r) / 2;
      int cl = cur * 2, cr = cur * 2 + 1;
      if (val >= sum[cl]) {
         return find(val - sum[cl], cr, mid, r);
      } else {
         return find(val, cl, l, mid);
      }
   }

   // returns the last idx such that sum [0, idx) <= val
   int find(ll val) {
      return find(val, 1, 0, size);
   }

   // FIND2
   int find2(ll val, int cur, int l, int r) {
      if (l + 1 == r) {
         if (min[cur] <= val) {
            return l;
         } else {
            return r;
         }
      }
      down(cur, l, r);
      int mid = (l + r) / 2;
      int cl = cur * 2, cr = cur * 2 + 1;
      if (min[cl] <= val) {
         return find2(val, cl, l, mid);
      } else {
         return find2(val, cr, mid, r);
      }
   }


   // returns the first idx such that min [0, idx) <= val
   int find2(ll val) {
      return find2(val, 1, 0, size);
   }
};


// ============= Solution ============= //
int sub_to_errichto() {
   int n, q;
   cin >> n >> q;
   vector<ll> v(n);
   for (ll &i: v) cin >> i;
   LazySeg seg(n);
   seg.build(v);
   for (int i = 0; i < q; ++i) {
      int t, x;
      ll y;
      cin >> t >> x >> y;
      --x;
      if (t == 1) {
         seg.setmax(0, x + 1, y);
      } else {
         int cur = x;
         int ans = 0;
         while (cur < n) {
            pp(cur, y);
            ll sum = seg.ask(0, cur);
            int nxt = min(n, seg.find(sum + y));
            ll sub = seg.ask(cur, nxt);
            pp(nxt, sub);
            ans += nxt - cur;
            y -= sub;
            cur = max(nxt, seg.find2(y));
         }
         cout << ans << "\n";
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