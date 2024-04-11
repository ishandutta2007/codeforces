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

template <int MOD_> struct modnum {
   static constexpr int MOD = MOD_;
   static_assert(MOD_ > 0, "MOD must be positive");
   private:
   using ll = long long;
   int v;
   static int minv(int a, int m) {
      a %= m;
      assert(a);
      return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
   }
   public:
   modnum() : v(0) {}
   modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
   explicit operator int() const { return v; }
   friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
   friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
   friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
   friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
   modnum inv() const {
      modnum res;
      res.v = minv(v, MOD);
      return res;
   }
   friend modnum inv(const modnum& m) { return m.inv(); }
   modnum neg() const {
      modnum res;
      res.v = v ? MOD-v : 0;
      return res;
   }
   friend modnum neg(const modnum& m) { return m.neg(); }
   modnum operator- () const {
      return neg();
   }
   modnum operator+ () const {
      return modnum(*this);
   }
   modnum& operator ++ () {
      v ++;
      if (v == MOD) v = 0;
      return *this;
   }
   modnum& operator -- () {
      if (v == 0) v = MOD;
      v --;
      return *this;
   }
   modnum& operator += (const modnum& o) {
      v += o.v;
      if (v >= MOD) v -= MOD;
      return *this;
   }
   modnum& operator -= (const modnum& o) {
      v -= o.v;
      if (v < 0) v += MOD;
      return *this;
   }
   modnum& operator *= (const modnum& o) {
      v = int(ll(v) * ll(o.v) % MOD);
      return *this;
   }
   modnum& operator /= (const modnum& o) {
      return *this *= o.inv();
   }
   friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
   friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
   friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
   friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
   friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
   friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

// ============= Solution ============= //
// augment array of pairs with mirror images;
// (a, b)--(c, d) --> (n - 1 - a, n - 1 - b) -- (n - 1 - c, n - 1 - d)
// check if there exists a path from central *lattice point* to border
//
// lattice point (a, b) is connected with (a + 1, b) if (a, b)--(a, b - 1) does not exist
// (a, b) is connected with (a, b + 1) if (a, b)--(a - 1, b - 1) does not exist
// edge points are (0, *), (n, *), (*, 0), (*, n); they are all connected

#define id(i, j) ((i)*(k+1)+(j))
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, k;
      cin >> n >> k;
      vector<pair<pii, pii>> pairs;
      for (int i = 0; i < n; ++i) {
         int a, b, c, d;
         cin >> a >> b >> c >> d;
         --a, --b, --c, --d;
         pairs.emplace_back(pii(a, b), pii(c, d));
      }
      int m = (k + 1) * (k + 1);
      multiset<pair<pii, pii>> s;
      for (auto p: pairs) {
         s.insert(p);
         s.insert(pair<pii, pii>(p.se, p.fi));
         s.insert(pair<pii, pii>(pii(k - 1 - p.fi.fi, k - 1 - p.fi.se), pii(k - 1 - p.se.fi, k - 1 - p.se.se)));
         s.insert(pair<pii, pii>(pii(k - 1 - p.se.fi, k - 1 - p.se.se), pii(k - 1 - p.fi.fi, k - 1 - p.fi.se)));
      }
      vector<vector<pii>> ed(m);
      for (int i = 0; i <= k; ++i) {
         for (int j = 0; j <= k; ++j) {
            if (i + 1 <= k) {
               ed[id(i, j)].push_back(pii(
                  id(i + 1, j), s.count(pair<pii, pii>(pii(i, j), pii(i, j - 1)))
               ));
            }
            if (j + 1 <= k) {
               ed[id(i, j)].push_back(pii(
                  id(i, j + 1), s.count(pair<pii, pii>(pii(i, j), pii(i - 1, j)))
               ));
            }
            if (i) {
               ed[id(i, j)].push_back(pii(
                  id(i - 1, j), s.count(pair<pii, pii>(pii(i - 1, j), pii(i - 1, j - 1)))
               ));
            }
            if (j) {
               ed[id(i, j)].push_back(pii(
                  id(i, j - 1), s.count(pair<pii, pii>(pii(i, j - 1), pii(i - 1, j - 1)))
               ));
            }
         }
      }

      using PQ = priority_queue<pii, vector<pii>, greater<pii>>;
      int inf = 1000 << 20;
      vector<int> dst(m, inf);
      int rt = id(k / 2, k / 2);
      pp(rt, ed[rt]);
      PQ pq;
      pq.push(pii(0, rt));
      dst[rt] = 0;
      pp(rt);
      pp(ed);
      while (sz(pq)) {
         pii p = pq.top();
         pq.pop();
         int cur = p.se;
         if (p.fi != dst[cur]) continue;
         for (pii e: ed[cur]) {
            if (dst[cur] + e.se < dst[e.fi]) {
               dst[e.fi] = dst[cur] + e.se;
               pq.push(pii(dst[cur] + e.se, e.fi));
            }
         }
      }
      pp(dst);
      int ans = n;
      for (int i = 0; i <= k; ++i) {
         ans = min(ans, dst[id(0, i)]);
         ans = min(ans, dst[id(i, 0)]);
      }
      cout << n - ans << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases