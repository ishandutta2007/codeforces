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

struct Line {
   mutable ll k, m, p;
   bool operator<(const Line& o) const { return k < o.k; }
   bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
   // (for doubles, use inf = 1/.0, div(a,b) = a/b)
   static const ll inf = LLONG_MAX;
   ll div(ll a, ll b) { // floored division
      return a / b - ((a ^ b) < 0 && a % b); }
   bool isect(iterator x, iterator y) {
      if (y == end()) return x->p = inf, 0;
      if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
      else x->p = div(y->m - x->m, x->k - y->k);
      return x->p >= y->p;
   }
   void add(ll k, ll m) {
      auto z = insert({k, m, 0}), y = z++, x = y;
      while (isect(y, z)) z = erase(z);
      if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
      while ((y = x) != begin() && (--x)->p >= y->p)
         isect(x, erase(y));
   }
   ll query(ll x) {
      assert(!empty());
      auto l = *lower_bound(x);
      return l.k * x + l.m;
   }
};

typedef priority_queue<pll, vector<pll>, greater<pll> > PQ;

// ============= Solution ============= //
int main() {
   // 1. find x, y such that [x, x+2] * [y, y + 2] fully contains the square
   // 2. ask [x, x + 1] * [y, y + 2]. let response be w. then x* = x + 1 - w
   // 3. ask [x, x + 2] * [y, y + 1]. y* = y + 1 - w
   //
   //
   // 1. start with x1 = 0, x2 = n, y1 = 0, y2 = m.
   // 1a. while x2 - x1 > 2 + eps, pick xm = (x1 + x2) / 2.0.
   // 1b. if [x1, xm] * [y1, y2] = 0 or 1, then set x1 or x2 to xm
   // 1c. otherwise, then set x1 = xm - 1, x2 = xm + 1

   double eps = 1e-8;
   int n, m;
   cin >> n >> m;
   n = 100;
   m = 100;

   double pix = 1e-4;
   using pdd = pair<double, double>;
   vector<pdd> poly = {{1, m + eps}};
   for (int i = 1; i < n; ++i) {
      poly.emplace_back(i, m);
      poly.emplace_back(i, 0);
      poly.emplace_back(i + i * pix, 0);
      poly.emplace_back(i + i * pix, m);
   }
   cout << "? " << sz(poly) << "\n";
   for (pdd p: poly) {
      cout << p.fi << " " << p.se << "\n";
   }
   cout.flush();
   double w;
   cin >> w;
   double x = w / pix;
   x += x * pix;

   cout << "? " << sz(poly) << "\n";
   for (pdd p: poly) {
      cout << p.se << " " << p.fi << "\n";
   }
   cout.flush();
   cin >> w;
   double y = w / pix;
   y += y * pix;

   poly = {
      {x - 1, y - 1},
      {x, y - 1},
      {x, y + 1},
      {x - 1, y + 1}
   };
   cout << "? " << sz(poly) << "\n";
   for (pdd p: poly) {
      cout << p.fi << " " << p.se << "\n";
   }
   cout.flush();
   cin >> w;

   poly = {
      {x - 1, y - 1},
      {x - 1, y},
      {x + 1, y},
      {x + 1, y - 1}
   };
   cout << "? " << sz(poly) << "\n";
   for (pdd p: poly) {
      cout << p.fi << " " << p.se << "\n";
   }
   cout.flush();
   double w2;
   cin >> w2;
   x -= w;
   y -= w2;
   cout << "! " << x << " " << y << endl;
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases