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
#define sub_to_errichto main
// =========== Book ============ //

// Returns all primes less than n
vector<int> listPrimes(int n) {
   vector<bool> sv(n);
   vector<int> res;
   for (int i = 2; i < n; ++i) {
      if (sv[i]) continue;
      res.push_back(i);
      for (int j = i; j <= (n - 1) / i; ++j) {
         sv[i * j] = 1;
      }
   }
   return res;
}

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
int sub_to_errichto() {
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> color(n);
   for (int &i: color) cin >> i, --i;
   vector<vector<int>> ed(n);
   map<pii, vector<pii>> colorPairToEdges;
   for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b; --a, --b;
      ed[a].push_back(b);
      ed[b].push_back(a);
      int c1 = color[a], c2 = color[b];
      if (c1 == c2) continue;
      if (c1 > c2) swap(c1, c2);
      colorPairToEdges[pii(c1, c2)].push_back(pii(a, b));
   }

   vector<int> ids(n, -1);
   vector<bool> bad(k);
   auto dfs = yc([&](auto rec, int cur) -> void {
      for (int nxt: ed[cur]) {
         if (color[nxt] != color[cur]) continue;
         if (ids[nxt] == ids[cur]) {
            bad[color[cur]] = true;
         }
         if (ids[nxt] == -1) {
            ids[nxt] = ids[cur] ^ 1;
            rec(nxt);
         }
      }
   });

   int idcnt = 0;
   for (int i = 0; i < n; ++i) {
      if (ids[i] == -1) {
         ids[i] = idcnt;
         dfs(i);
         idcnt += 2;
      }
   }

   int goodColors = k;
   for (int i = 0; i < k; ++i) {
      if (bad[i]) --goodColors;
   }

   vector<int> par(idcnt);
   for (int i = 0; i < idcnt; ++i) {
      par[i] = i;
   }
   auto find = yc([&](auto rec, int x) -> int {
      if (par[x] == x) return x;
      return par[x] = rec(par[x]);
   });
   auto join = [&](int a, int b) -> void {
      a = find(a);
      b = find(b);
      par[a] = b;
   };
   pp(ids);
   ll ans = 1LL * goodColors * (goodColors - 1) / 2;
   for (auto v: colorPairToEdges) {
      if (bad[v.fi.fi] || bad[v.fi.se]) continue;
      set<pii> seen;
      for (pii p: v.se) {
         int a = ids[p.fi];
         int b = ids[p.se];
         if (find(a) == find(b)) {
            pp(v);
            --ans;
            break;
         }
         join(a ^ 1, b);
         join(a, b ^ 1);
      }
      for (pii p: v.se) {
         int a = ids[p.fi];
         int b = ids[p.se];
         par[a] = a;
         par[a ^ 1] = a ^ 1;
         par[b] = b;
         par[b ^ 1] = b ^ 1;
      }
   }

   cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases