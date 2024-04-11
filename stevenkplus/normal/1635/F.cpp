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
// sweep queries i in desc l
// update dp[j] = (x[j] - x[prv[j]]) * (w[j] + w[prv[j]]) for all j where:
// - prv[j] is the first pos to left of j with smaller (or equal) w value
// - prv[j] is newly in range (prv[j] >= i)
// do a range query to see min value of dp over [l[i], r[i] + 1)
// set ans[i] = ask(l[i], r[i] + 1)
// repeat for "going to the right" candidates by doing x *= -1, (l, r) = n - 1 - (l, r)

int main() {
   int n, q;
   cin >> n >> q;
   vector<int> x(n), w(n);
   for (int i = 0; i < n; ++i) cin >> x[i] >> w[i];
   vector<int> L(q), R(q);
   for (int i = 0; i < q; ++i) cin >> L[i] >> R[i], --L[i];

   const ll infl = 1LL << 62;
   vector<ll> ans(q, infl);
   for (int rep = 0; rep < 2; ++rep) {
      vector<int> prv(n);
      vector<int> queue = {-1};
      for (int i = 0; i < n; ++i) {
         while (queue.back() != -1 && w[queue.back()] > w[i]) {
            queue.pop_back();
         }
         prv[i] = queue.back();
         queue.push_back(i);
      }
      vector<ll> vals(n);
      for (int i = 0; i < n; ++i) {
         vals[i] = prv[i] == -1 ? infl : 1LL * (x[i] - x[prv[i]]) * (w[i] + w[prv[i]]);
      }
      pp(x);
      pp(w);
      pp(prv);
      pp(vals);
      vector<vector<int>> layers(n);
      for (int i = 0; i < n; ++i) {
         if (prv[i] == -1) continue;
         layers[prv[i]].push_back(i);
      }
      vector<pii> byL(q);
      for (int i = 0; i < q; ++i) {
         byL[i].fi = L[i];
         byL[i].se = i;
      }
      sort(byL.begin(), byL.end());
      reverse(byL.begin(), byL.end());
      int cur = n - 1;

      vector<ll> seg(2 * n, infl);
      for (pii p: byL) {
         pp(p.se, L[p.se], R[p.se]);
         while (cur >= p.fi) {
            pp(cur);
            for (int k: layers[cur]) {
               ll v = vals[k];
               for (k += n; k; k /= 2) {
                  seg[k] = min(seg[k], v);
               }
            }
            --cur;
         }
         ll res = infl;
         for (int l = L[p.se] + n, r = R[p.se] + n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = min(res, seg[l++]);
            if (r & 1) res = min(res, seg[--r]);
         }
         pp(res);
         ans[p.se] = min(ans[p.se], res);
      }
      reverse(x.begin(), x.end());
      reverse(w.begin(), w.end());
      for (int i = 0; i < q; ++i) {
         L[i] = n - L[i];
         R[i] = n - R[i];
         swap(L[i], R[i]);
      }
      for (int &i: x) i *= -1;
   }
   for (ll i: ans) {
      cout << i << "\n";
   }

}


// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases