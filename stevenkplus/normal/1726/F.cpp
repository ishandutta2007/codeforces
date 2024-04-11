// =========== Template ========== //
#include <bits/stdc++.h>
// #include<bits/extc++.h>
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
using vi = vector<int>;
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
// struct splitmix64_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } }; // https://github.com/ecnerwala/cp-book/blob/master/src/hash_map.hpp
// struct splitmix64_hash_pll { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(pll x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x.fi * 132453374217LL + x.se + FIXED_RANDOM); } }; // https://github.com/ecnerwala/cp-book/blob/master/src/hash_map.hpp thanks kevin
// template <typename K, typename V, typename Hash = splitmix64_hash> using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
// template <typename K, typename Hash = splitmix64_hash> using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;
// hash_map<ll, ll> hm; hash_map<pll, pll, splitmix64_hash_pll> hm2;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ============= Solution ============= //

class LazySeg {
   public:
   int size;
   vector<ll> lazy;
   vector<ll> data;
   LazySeg(int _size) {
      size = 1;
      while (size < _size) size *= 2;
      data = vector<ll>(size * 2);
      lazy = vector<ll>(size * 2, -1);
   }
   // BUILD
   void build(vector<ll> &ar, int cur, int l, int r) {
      if (l + 1 == r) {
         data[cur] = ar[l];
      } else {
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         build(ar, cl, l, mid);
         build(ar, cr, mid, r);
      }
   }
   void build(vector<ll> &ar) {
      build(ar, 1, 0, size);
   }
   void build(ll *ar, int cur, int l, int r) {
      if (l + 1 == r) {
         data[cur] = ar[l];
      }
   }
   void build(ll *ar) {
      build(ar, 1, 0, size);
   }
   void down(int cur, int l, int r) {
      int cl = cur * 2, cr = cur * 2 + 1;
      if (lazy[cur] != -1) {
         data[cl] = lazy[cur];
         data[cr] = lazy[cur];
         lazy[cl] = lazy[cur];
         lazy[cr] = lazy[cur];
         lazy[cur] = -1;
      }
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
         data[cur] = val;
      } else if (left >= r || l >= right) {
      } else {
         down(cur, l, r);
         int mid = (l + r) / 2;
         int cl = cur * 2, cr = cur * 2 + 1;
         set(left, right, val, cl, l, mid);
         set(left, right, val, cr, mid, r);
      }
   }
   void set(int left, int right, ll val) {
      set(left, right, val, 1, 0, size);
   }
};

int main() {
   int n, t;
   cin >> n >> t;
   pp(n, t);
   vector<ll> G(n), C(n);
   for (int i = 0; i < n; ++i) {
      cin >> G[i] >> C[i];
   }
   vector<ll> d(n - 1);
   for (int i = 0; i < n; ++i) {
      cin >> d[i];
   }

   // G[i], C[i] -= D[j] for all j < i
   vector<ll> left(n), right(n);
   ll sum = 0;
   for (int i = 0; i < n; ++i) {
      C[i] = (C[i] + sum % t) % t;
      left[i] = (t + G[i] - C[i]) % t;
      right[i] = (t - C[i]) % t;
      pp(i, C[i], sum, left[i]);
      if (i < n - 1) {
         sum = sum + d[i];
      }
   }
   pp(left, right);

   map<ll, int> coord;
   for (int i = 0; i < n; ++i) {
      coord[left[i]] = -1;
      coord[right[i]] = -1;
      if (left[i]) coord[left[i] - 1] = -1;
      if (right[i]) coord[right[i] - 1] = -1;
   }
   coord[t - 1] = -1;
   int m = 0;
   vector<ll> coords;
   for (auto &p: coord) {
      coords.push_back(p.fi);
      p.se = m++;
   }
   pp(coords);
   // segtree over m. v[i] = completion time if starting at time i
   // support range_set([l, r), val)
   // go backwards
   int size = 1;
   while (size < m) size *= 2;
   vector<ll> vals(size);
   for (int i = 0; i < m; ++i) {
      vals[i] = coords[i];
   }
   LazySeg seg(size);
   seg.build(vals);
   pp(seg.data);
   for (int i = n - 1; i >= 0; --i) {
      int l = coord[left[i]];
      int r = coord[right[i]];
      ll val = seg.ask(r, r + 1);
      // vector<ll> debug;
      // for (int j = 0; j < m; ++j) {
         // debug.push_back(seg.ask(j, j + 1));
      // }
      // pp(debug);
      pp(i, l, r);
      pp(val);
      if (l < r) {
         seg.set(l, r, val);
      } else {
         seg.set(l, m, val + t);
         seg.set(0, r, val);
      }
   }

   pp(seg.data);
   const ll infl = 1LL << 60;
   ll ans = infl;
   for (int i = 0; i < m; ++i) {
      ll val = seg.ask(i, i + 1) - coords[i];
      pp(i, val);
      ans = min(ans, val);
   }
   ans += sum;
   cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases