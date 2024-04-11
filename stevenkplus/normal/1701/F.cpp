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
struct node;
ostream& operator<<(ostream &os, const node &node);
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
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;

struct node {
   ll p = 0;
   ll val = 0;
};
node operator+(node a, node b) {
   return {
      a.p + b.p,
      a.val + b.val,
   };
}
class LazySeg {
   int size;
   vector<node> data;
   vector<ll> lazy;
   public:
   LazySeg(int _size) {
      size = 1;
      while (size < _size) size *= 2;
      data = vector<node>(size * 2);
      lazy = vector<ll>(size * 2);
   }
   void down(int cur, int l, int r) {
      int cl = cur * 2, cr = cur * 2 + 1;
      ll diff = lazy[cur];
      data[cl].val += diff * data[cl].p;
      data[cr].val += diff * data[cr].p;
      lazy[cl] += lazy[cur];
      lazy[cr] += lazy[cur];
      lazy[cur] = 0;
   }
   // ASK
   node ask(int left, int right, int cur, int l, int r) {
      if (left <= l && r <= right) {
         return data[cur];
      } else if (left >= r || l >= right) {
         return {};
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

   // ADDP
   void addp(int x, ll val, int cur, int l, int r) {
      if (x >= r || l > x) {
         // pass
      } else if (l + 1 == r) {
         data[cur].p += val;
         data[cur].val += val * lazy[cur];
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         addp(x, val, cl, l, mid);
         addp(x, val, cr, mid, r);
         data[cur] = data[cl] + data[cr];
      }
   }
   void addp(int x, ll val) {
      addp(x, val, 1, 0, size);
   }

   // ADDV
   void addv(int left, int right, ll val, int cur, int l, int r) {
      if (left <= l && r <= right) {
         lazy[cur] += val;
         data[cur].val += val * data[cur].p;
      } else if (left >= r || l >= right) {
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         addv(left, right, val, cl, l, mid);
         addv(left, right, val, cr, mid, r);
         data[cur] = data[cl] + data[cr];
      }
   }
   void addv(int left, int right, ll val) {
      addv(left, right, val, 1, 0, size);
   }

};

// ============= Solution ============= //
// v[i] = # points in [i + 1, i + d]
// p[i] = 1 if i is in set
// ans = sum(p[i] * v[i] choose 2)
// insert -> ans += sum(p[i] * v[i]) over i-d...i-1; ans += v[i] choose 2; p[i] += 1; v[i-d...i-1] += 1

int main() {
   int q, d;
   cin >> q >> d;
   const int n = 1 << 18;
   LazySeg seg(n);
   set<int> s;
   ll ans = 0;
   while (q--) {
      int x;
      cin >> x;
      pp(x, s.count(x));
      if (!s.count(x)) {
         ans += seg.ask(max(0, x - d), x).val;
         pp(seg.ask(max(0, x - d), x).val);
         seg.addp(x, 1);
         seg.addv(max(0, x - d), x, 1);
         ll v = seg.ask(x, x + 1).val;
         pp(v);
         ans += v * (v - 1) / 2;
         s.insert(x);
      } else {
         ll v = seg.ask(x, x + 1).val;
         ans -= v * (v - 1) / 2;
         seg.addp(x, -1);
         seg.addv(max(0, x - d), x, -1);
         ans -= seg.ask(max(0, x - d), x).val;
         s.erase(x);
      }
      pp(ans);
      cout << ans << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases