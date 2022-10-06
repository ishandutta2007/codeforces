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

const ld eps = 1E-10;
const int inf = 1000 << 20;
int sub_to_errichto() {
   int n;
   cin >> n;
   vector<pair<int, pii>> edges;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         int a;
         cin >> a;
         if (i >= j) continue;
         edges.emplace_back(a, pii(i, j));
      }
   }
   sort(edges.begin(), edges.end());
   vector<int> ndcnt(n), edcnt(n);
   vector<int> par(n);
   for (int i = 0; i < n; ++i) {
      par[i] = i;
      ndcnt[i] = 1;
   }

   auto find = yc([&](auto find, int x) -> int {
      if (par[x] == x) return x;
      return par[x] = find(par[x]);
   });

   vector<vector<int>> cliques; // at most 2n cliques total
   for (int i = 0; i < n; ++i) {
      cliques.push_back(vector<int>({i}));
   }
   for (auto ed: edges) {
      int i = ed.se.fi, j = ed.se.se;
      i = find(i), j = find(j);
      if (i != j) {
         par[j] = i;
         ndcnt[i] += ndcnt[j];
         edcnt[i] += edcnt[j];
      }
      ++edcnt[i];

      if (edcnt[i] == ndcnt[i] * (ndcnt[i] - 1) / 2) {
         vector<int> v;
         for (int k = 0; k < n; ++k) {
            if (find(k) == i) {
               v.push_back(k);
            }
         }
         pp(i, edcnt[i], ndcnt[i], v);
         cliques.push_back(v);
      }
   }

   int m = sz(cliques);
   vector<pii> order(m);
   for (int i = 0; i < m; ++i) {
      order[i] = pii(sz(cliques[i]), i);
   }
   sort(order.begin(), order.end()); // order cliques in increasing order of size
   using mint = modnum<998244353>;

   auto convolve = [&](vector<mint> a, vector<mint> b) -> vector<mint> {
      int n = sz(a), m = sz(b);
      vector<mint> ret(n + m - 1);
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            ret[i + j] += a[i] * b[j];
         }
      }
      return ret;
   };

   pp(cliques);
   vector<int> last(n, -1);
   vector<vector<mint>> ans(m);
   for (int i = 0; i < m; ++i) {
      set<int> children;
      for (int el: cliques[i]) {
         if (last[el] != -1) {
            children.insert(last[el]);
         }
         last[el] = i;
      }
      if (sz(children) == 0) {
         ans[i] = vector<mint>({0, 1});
      } else {
         vector<mint> ways({1});
         for (int ch: children) {
            ways = convolve(ways, ans[ch]);
         }
         ++ways[1];
         ans[i] = ways;
      }
   }

   pp(ans);
   ans[m - 1].resize(n + 1);
   for (int i = 1; i <= n; ++i) {
      cout << ans[m - 1][i] << " ";
   }
   cout << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases