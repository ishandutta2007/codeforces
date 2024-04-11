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
// A[i] = cost to get from top left to [1][i] -- either by hitting [1][i-1] or [0][i]
// C[i] = cost to get from [1][i] to bottom right
//
// 1. compute A and C without accounting for unlocks
//   - A[i] = pref sum(G[0][i+1]-G[1][i])
//   - C[i] = suff sum(G[2][i-1]-G[1][i])
//   ans = A[i]+C[i]+k + sum(G[1][i]) + G[0][0] + G[2][n-1]
// 2. update A by accounting for all unlocks (in order of l)
//   - A[r + 1] <= min_{l <= i <= r}(A[i]) + k
// 3. compute answer by iterating over each "rightmost unlock" -- min_{l <= i <= j <= r} A[i] + C[j] + k

struct node {
   ll maxA, maxC, maxAC;
};
node operator+(node a, node b) {
   return {
      max(a.maxA, b.maxA),
      max(a.maxC, b.maxC),
      max(a.maxA + b.maxC, max(a.maxAC, b.maxAC)),
   };
}


int main() {
   int n, q;
   cin >> n >> q;
   vector<vector<int>> G(3, vector<int>(n));
   for (auto &v: G) for (auto &i: v) cin >> i;
   vector<ll> A(n), C(n);
   for (int i = 0; i + 1 < n; ++i) {
      A[i + 1] = A[i] + G[0][i + 1] - G[1][i];
   }
   for (int i = n - 2; i >= 0; --i) {
      C[i] = C[i + 1] + G[2][i] - G[1][i + 1];
   }

   pp(A);

   ll infl = 1LL << 60;
   int size = 1;
   while (size < n) size *= 2;
   vector<ll> segA(size * 2, -infl);
   for (int i = 0; i < n; ++i) segA[i + size] = A[i];
   for (int i = size - 1; i; --i) segA[i] = max(segA[i * 2], segA[i * 2 + 1]);

   auto setA = [&](int i, ll val) -> void {
      A[i] = val;
      for (segA[i += size] = val; i / 2; i /= 2) {
         segA[i / 2] = max(segA[i], segA[i ^ 1]);
      }
   };
   auto askA = [&](int l, int r) -> ll {
      ll res = -infl;
      for (l += size, r += size; l < r; l /= 2, r /= 2) {
         if (l & 1) res = max(res, segA[l++]);
         if (r & 1) res = max(res, segA[--r]);
      }
      return res;
   };

   pp(A);
   pp(segA);
   pp(askA(1, 3));
   vector<pair<pii, int>> offers(q);
   for (auto &off: offers) {
      cin >> off.fi.fi >> off.fi.se >> off.se;
      --off.fi.fi, --off.fi.se;
   }
   sort(offers.begin(), offers.end());
   for (auto off: offers) {
      int l = off.fi.fi, r = off.fi.se, k = off.se;
      if (r + 1 >= n) continue;
      ll val = -k + askA(l, r + 1);
      pp(l, r, k, val);
      pp(askA(l, r + 1));
      setA(r + 1, max(A[r + 1], val));
   }
   vector<node> seg(size * 2);
   for (int i = 0; i < n; ++i) {
      seg[i + size] = {A[i], C[i], A[i] + C[i]};
   }
   for (int i = size - 1; i; --i) {
      seg[i] = seg[i * 2] + seg[i * 2 + 1];
   }
   auto ask = [&](int l, int r) -> node {
      node resl = {-infl, -infl, -infl}, resr = resl;
      for (l += size, r += size; l < r; l /= 2, r /= 2) {
         if (l & 1) resl = resl + seg[l++];
         if (r & 1) resr = seg[--r] + resr;
      }
      return resl + resr;
   };
   pp(A);
   pp(C);

   ll ans = -infl;
   for (auto off: offers) {
      int l = off.fi.fi, r = off.fi.se, k = off.se;
      pp(l, r, k);
      node res = ask(l, r + 1);
      pp(res.maxA, res.maxC, res.maxAC);
      ans = max(ans, res.maxAC - k);
   }

   ll offset = G[0][0] + G[2][n - 1];
   for (int i = 0; i < n; ++i) offset += G[1][i];

   pp(offset);
   ans += offset;
   cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases