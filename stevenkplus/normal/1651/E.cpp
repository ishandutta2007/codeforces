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

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
// ============= Solution ============= //
// each node has in[] and out[]
// A = {0...n-1} and B = {n...2n-1}
//
// iterate over all i 0...2n-1.
// s[-1] = in[i], or null if i is not seen before
// s[0] = i
// s[1] = out[i]
// s[2] = out[out[i]]
// ...
// s[2k-1] = in[i]
// s[2k] = i
//
//
// then, there are 2 terms:
// 1) for each j: if s[-1] not in range, s[0] ... s[2j-1] in range
//    -> contribution = 1

int main() {
   int n;
   cin >> n;
   vector<vector<int>> ed(2 * n);
   for (int i = 0; i < 2 * n; ++i) {
      int a, b;
      cin >> a >> b, --a, --b;
      ed[a].push_back(b);
      ed[b].push_back(a);
   }
   pp(ed);
   vector<bool> first(2 * n);
   vector<int> in(2 * n, -1), out(2 * n, -1);
   for (int i = 0; i < 2 * n; ++i) {
      if (in[i] == -1) {
         first[i] = true;
         int cur = i;
         do {
            out[cur] = ed[cur][0] == in[cur] ? ed[cur][1] : ed[cur][0];
            in[out[cur]] = cur;
            cur = out[cur];
         } while (cur != i);
      }
   }
   pp(in);
   pp(out);

   auto calc = [&](pii p) -> ll {
      if (p.fi >= n) p.fi -= n, p.se -= n;
      return (p.fi + 1) * (n - p.se);
   };

   auto calc2 = [&](pii p, int excl) -> ll {
      if (p.fi >= n) p.fi -= n, p.se -= n, excl -= n;
      if (excl < p.fi) {
         return (p.fi - excl) * (n - p.se);
      } else if (excl > p.se) {
         return (p.fi + 1) * (excl - p.se);
      } else return 0;
   };

   ll ans = 0;
   for (int i = 0; i < 2 * n; ++i) {
      int cur = i;
      pii a(cur, cur);
      pii b(out[cur], out[cur]);
      int cnt = 1;
      while (out[cur] != in[i]) {
         ans += calc(a) * calc2(b, in[i]);
         cur = out[out[cur]];
         a.fi = min(a.fi, cur);
         a.se = max(a.se, cur);
         b.fi = min(b.fi, out[cur]);
         b.se = max(b.se, out[cur]);
         cnt += 1;
      }
      if (first[i]) {
         ans += cnt * calc(a) * calc(b);
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