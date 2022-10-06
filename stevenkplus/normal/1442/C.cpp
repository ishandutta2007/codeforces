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

const int MAXN = 1000000;
const int MAXK = 20;

ll dist[MAXN][MAXK];

// ============= Solution ============= //
int sub_to_errichto() {
   using mint = modnum<998244353>;
   // check for K < 20
   // for K > 20, just treat transpositions as cost=MAXN. Mod & Div at end to figure out what K actually was

   int n, m;
   cin >> n >> m;
   vector<vector<int>> ed[2] = {vector<vector<int>>(n)};
   ed[1] = vector<vector<int>>(n);
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v, --u, --v;
      ed[0][u].push_back(v);
      ed[1][v].push_back(u);
   }

   const ll infl = 1LL << 60;
   auto reset = [&]() {
      for (int i = 0; i < n; ++i) {
         for (int k = 0; k < MAXK; ++k) {
            dist[i][k] = infl;
         }
      }
   };

   using node = pair<ll, pii>;
   using PQ = priority_queue<node, vector<node>, greater<node> >;

   PQ pq;
   bool shouldMod = true;
   auto enq = [&](int i, int k, ll d) -> void {
      if (shouldMod) {
         k %= 2;
      }
      if (k >= MAXK) return;
      if (d < dist[i][k]) {
         dist[i][k] = d;
         pq.push(node(d, pii(i, k)));
      }
   };


   vector<ll> globalAns(2);
   vector<ll> localAns(MAXK);
   for (int rep = 0; rep < 2; ++rep) {
      pp("Dijk", rep);
      reset();
      enq(0, 0, 0);
      while (!pq.empty()) {
         node cur = pq.top(); pq.pop();
         pii p = cur.se;

         for (int nxt: ed[p.se % 2][p.fi]) {
            enq(nxt, p.se, cur.fi + 1);
         }

         enq(p.fi, p.se + 1, cur.fi + MAXN);
      }
      if (rep == 0) {
         for (int i = 0; i < 2; ++i) {
            globalAns[i] = dist[n - 1][i];
         }
      } else {
         for (int i = 0; i < MAXK; ++i) {
            localAns[i] = dist[n - 1][i];
         }
      }
      shouldMod = false;
   }
   pp(globalAns);
   pp(localAns);

   vector<ll> pows(MAXK);
   vector<mint> mpows(MAXN);
   mpows[0] = pows[0] = 1;
   for (int i = 0; i + 1 < MAXK; ++i) {
      pows[i + 1] = pows[i] * 2;
   }
   for (int i = 0; i < MAXN; ++i) {
      mpows[i + 1] = mpows[i] * 2;
   }
   mint gans;
   ll ans = infl;
   for (ll i: localAns) {
      if (i == infl) continue;
      ll val = pows[i / MAXN] + i % MAXN;
      ans = min(ans, val);
   }
   if (ans == infl) { // then use a global ans
      ll g = min(globalAns[0], globalAns[1]);
      gans = mpows[g / MAXN] + g % MAXN;
   } else {
      gans = ans;
   }
   --gans;

   cout << gans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases