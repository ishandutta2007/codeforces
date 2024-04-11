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
int main() {
   int n, k;
   cin >> n >> k;
   vector<vector<int>> edges(n); // edges[i]: when you have i 0s, k - i 1s
   vector<vector<int>> invEdges(n + 1);
   for (int i = 0; i < n; ++i) {
      int j = n - i;
      for (int x = 0; x <= k; ++x) {
         if (x > i || k - x > j) continue;
         edges[i].push_back(i - x + k - x);
         invEdges[i - x + k - x].push_back(i);
      }
   }
   int inf = 1000 << 20;
   vector<int> dist(n + 1, inf);
   dist[0] = 0;
   vector<bool> vis(n);
   for (int rep = 0; rep < n; ++rep) {
      int bst = -1;
      for (int i = 0; i < n; ++i) {
         if (vis[i]) continue;
         if (bst == -1 || dist[i] < dist[bst]) bst = i;
      }
      vis[bst] = true;
      for (int i: edges[bst]) {
         dist[i] = min(dist[i], dist[bst] + 1);
      }
   }

   if (dist[n] == inf) {
      cout << -1 << endl;
   } else {
      vector<int> path = {n};
      while (path.back() != 0) {
         for (int i: invEdges[path.back()]) {
            if (dist[i] == dist[path.back()] - 1) {
               path.push_back(i);
               break;
            }
         }
      }
      reverse(path.begin(), path.end());
      vector<int> zeros;
      vector<int> ones;

      pp(path);
      int ans = 0;
      for (int i = 1; i <= n; ++i) zeros.push_back(i);
      for (int idx = 0; idx  + 1 < sz(path); ++idx) {
         int cur = path[idx];
         int nxt = path[idx + 1];
         int x;
         for (x = 0; x <= k; ++x) {
            if (x > cur || k - x > n - cur) continue;
            if (cur - x + k - x == nxt) {
               break;
            }
         }

         vector<int> query;
         vector<int> poppedZeros;
         pp(x, k);
         for (int i = 0; i < k - x; ++i) {
            query.push_back(zeros.back());
            poppedZeros.push_back(zeros.back());
            zeros.pop_back();
         }
         for (int i = 0; i < x; ++i) {
            query.push_back(ones.back());
            zeros.push_back(ones.back());
            ones.pop_back();
         }
         pp(query);
         for (int i: poppedZeros) {
            ones.push_back(i);
         }

         cout << "?";
         for (int i: query) {
            cout << " " << i;
         }
         cout << endl;
         cin >> x;
         ans ^= x;
      }

      cout << "! " << ans << "\n";

   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases