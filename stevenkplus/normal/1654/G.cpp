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
// a node x is "friendly" if there exists a neighbor y of x such that h[x] = h[y]
// for each node, compute the minimum h[x] over all reachable friendly nodes x
// note that sum(h[x]) over all reachable friendly nodes x is at most n
// therefore the set H of distinct h[x] values has size at most O(sqrt n)
//
// solve the following dp problem for each value w in H in O(n) time:
// dp[i] = minimum energy needed to be able to reach a friendly node x with h[x] = w
// children[i] = j such that h[j] = h[i] - 1
// neighbors[i] = k such that h[k] = h[i]
//
// dp[i] <= dp[j] - 1
// dp[i] <= dp[k] + 1
// so, first relax all child edges, then do a bfs within each layer to compute correct dp values
//
//
// if dp[i] = 0, that means that ans[i] is at least 2 * h[i] - w.
// thus the total runtime is O(n sqrt n) which might pass for n = 2E5 and TL = 5 seconds...
//
// |H| = sqrt(2n) = sqrt(4E5) ~ 630
// runtime of dp problem = relaxing n edges. possibly involves a sort that can be done via counting sort, but can skip this by keeping each layer sorted by dp.

int main() {
   int n;
   cin >> n;
   vector<int> L(n);
   for (int &i: L) cin >> i;
   vector<vector<int>> ed(n);
   for (int i = 0; i < n - 1; ++i) {
      int x, y; cin >> x >> y; --x, --y;
      ed[x].push_back(y);
      ed[y].push_back(x);
   }

   int inf = 1000 << 20;
   vector<int> h(n, inf);
   vector<bool> friendly(n);
   vector<int> q;
   for (int i = 0; i < n; ++i) {
      if (L[i]) {
         h[i] = 0;
         q.push_back(i);
      }
   }
   for (int ql = 0; ql < sz(q); ++ql) {
      for (int nxt: ed[q[ql]]) {
         if (h[nxt] == h[q[ql]]) friendly[q[ql]] = true;
         if (h[nxt] != inf) continue;
         h[nxt] = h[q[ql]] + 1;
         q.push_back(nxt);
      }
   }

   set<int> H;
   for (int i = 0; i < n; ++i) {
      if (friendly[i]) H.insert(h[i]);
   }

   vector<vector<int>> layers(n), up(n), side(n);
   for (int i = 0; i < n; ++i) {
      layers[h[i]].push_back(i);
      for (int j: ed[i]) {
         if (h[j] == h[i]) side[i].push_back(j);
         else if (h[j] == h[i] + 1) up[i].push_back(j);
      }
   }
   vector<int> ans(n, -1);
   for (int w: H) {
      vector<int> dp(n, inf);
      vector<int> cur;
      for (int i: layers[w]) {
         if (friendly[i] && ans[i] == -1) {
            dp[i] = 0;
            cur.push_back(i);
         }
      }
      vector<int> nxt;
      while (sz(cur)) {
         int ql = 0;
         vector<int> q;
         for (int i = 0; i <= sz(cur); ++i) {
            int v = i < sz(cur) ? max(0, dp[cur[i]] - 1) : inf;
            while (ql < sz(q) && dp[q[ql]] < v) {
               int k = q[ql++];
               for (int j: side[k]) {
                  if (dp[j] > dp[k] + 1 && ans[j] == -1) {
                     dp[j] = dp[k] + 1;
                     q.push_back(j);
                  }
               }
            }
            if (i == sz(cur)) break;
            pp(w, cur[i], dp[cur[i]], up[cur[i]]);
            for (int j: up[cur[i]]) {
               if (dp[j] == inf && ans[j] == -1) {
                  dp[j] = v;
                  q.push_back(j);
               }
            }
            if (dp[cur[i]] == 0) ans[cur[i]] = 2 * h[cur[i]] - w;
         }
         cur = q;
      }
      pp(w, dp);
   }

   for (int i = 0; i < n; ++i) {
      if (ans[i] == -1) ans[i] = h[i];
      cout << ans[i] << " ";
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