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

class LazySeg {
   int size;
   vector<ll> data;
   vector<ll> lazy;
   public:
   LazySeg(int _size) {
      size = 1;
      while (size < _size) size *= 2;
      data = vector<ll>(size * 2);
      lazy = vector<ll>(size * 2, -1);
   }
   // BUILD
   void build(ll *ar, int cur, int l, int r) {
      if (l + 1 == r) {
         data[cur] = ar[l];
      } else {
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         build(ar, cl, l, mid);
         build(ar, cr, mid, r);
         data[cur] = data[cl] + data[cr];
      }
   }
   void build(ll *ar) {
      build(ar, 1, 0, size);
   }
   void down(int cur, int l, int r) {
      if (!lazy[cur]) return;
      int cl = cur * 2, cr = cur * 2 + 1;
      ll diff = lazy[cur] * (r - l) / 2;
      data[cl] = diff;
      data[cr] = diff;
      lazy[cl] = lazy[cur];
      lazy[cr] = lazy[cur];
      lazy[cur] = 0;
   }
   // ASK
   ll ask(int left, int right, int cur, int l, int r) {
      if (left <= l && r <= right) {
         return data[cur];
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
   // SET
   void set(int left, int right, ll val, int cur, int l, int r) {
      if (left <= l && r <= right) {
         lazy[cur] = val;
         data[cur] = val * (r - l);
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
   void set(int left, int right, ll val) {
      set(left, right, val, 1, 0, size);
   }
};




// ============= Solution ============= //

int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, q;
      cin >> n >> q;
      string aInp, bInp;
      cin >> aInp >> bInp;

      vector<int> a(n), b(n);
      for (int i = 0; i < n; ++i) {
         a[i] = aInp[i] == '1' ? 1 : -1;
         b[i] = bInp[i] == '1' ? 1 : -1;
      }

      vector<int> l(q), r(q);
      for (int i = 0; i < q; ++i) {
         cin >> l[i] >> r[i];
         --l[i];
      }
      reverse(l.begin(), l.end());
      reverse(r.begin(), r.end());

      LazySeg seg(n);
      for (int i = 0; i < n; ++i) {
         seg.set(i, i + 1, b[i]);
      }

      auto dbg = [&]() {
         vector<int> fin(n);
         for (int i = 0; i < n; ++i) {
            fin[i] = seg.ask(i, i + 1);
         }
         pp(fin);
      };

      string ans = "YES";
      for (int i = 0; i < q; ++i) {
         int v = seg.ask(l[i],  r[i]);
         if (v == 0) ans = "NO";
         pp(l[i], r[i], v);
         // dbg();
         seg.set(l[i], r[i], v > 0 ? 1 : -1);
      }
      vector<int> fin(n);
      for (int i = 0; i < n; ++i) {
         fin[i] = seg.ask(i, i + 1);
         if (a[i] != fin[i]) {
            ans = "NO";
         }
      }

      pp(fin);
      cout << ans << "\n";
   }

}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases