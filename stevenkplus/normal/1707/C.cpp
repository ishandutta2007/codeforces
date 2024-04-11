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

int MOD;

struct modnum {
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
int main() {
   int n, m;
   cin >> n >> m;
   vector<int> par(n);
   vector<vector<int>> ed(n);
   auto find = yc([&](auto rec, int x) -> int {
      if (par[x] == x) return x;
      return par[x] = rec(par[x]);
   });
   vector<pii> cross;
   for (int i = 0; i < n; ++i) {
      par[i] = i;
   }
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v; --u, --v;
      if (find(u) == find(v)) {
         cross.push_back(pii(u, v));
      } else {
         ed[u].push_back(v);
         ed[v].push_back(u);
         par[find(u)] = find(v);
      }
   }

   par = vector<int>(n);
   vector<int> depth(n);

   yc([&](auto rec, int cur) -> void {
      for (int nxt: ed[cur]) {
         if (nxt == par[cur]) continue;
         par[nxt] = cur;
         depth[nxt] = depth[cur] + 1;
         rec(nxt);
      }
   })(0);
   vector<vector<int>> jump(20, vector<int>(n));
   jump[0] = par;
   for (int i = 0; i + 1 < 20; ++i) {
      for (int j = 0; j < n; ++j) {
         jump[i + 1][j] = jump[i][jump[i][j]];
      }
   }

   auto path = [&](int a, int b) -> int {
      if (depth[a] < depth[b]) swap(a, b);
      int diff = depth[a] - depth[b] - 1;
      for (int i = 0; i < 20; ++i) {
         if ((diff >> i) & 1) {
            a = jump[i][a];
         }
      }
      return a;
   };

   auto is_anc = [&](int a, int b) -> bool {
      if (depth[a] < depth[b]) swap(a, b);
      int diff = depth[a] - depth[b];
      for (int i = 0; i < 20; ++i) {
         if ((diff >> i) & 1) {
            a = jump[i][a];
         }
      }
      return a == b;
   };


   vector<int> cnts(n);
   for (auto p: cross) {
      int a = p.fi, b = p.se;
      if (is_anc(a, b)) {
         if (depth[a] < depth[b]) swap(a, b);
         ++cnts[a];
         ++cnts[0];
         --cnts[path(a, b)];
      } else {
         ++cnts[a];
         ++cnts[b];
      }
   }

   yc([&](auto rec, int cur) -> void {
      for (int nxt: ed[cur]) {
         if (nxt == par[cur]) continue;
         cnts[nxt] += cnts[cur];
         rec(nxt);
      }
   })(0);

   pp(cross);
   pp(cnts);
   for (int i = 0; i < n; ++i) {
      if (cnts[i] == sz(cross)) {
         cout << "1";
      } else {
         cout << "0";
      }
   }
   cout << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases