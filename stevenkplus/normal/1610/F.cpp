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
// Combine edges until there's at most 1 edge of weight 1 and 1 edge of weight 2 incident at any node
// 2 color the resulting graph (colors red & blue)
// Direct all edges red->blue
// Recover original edges
//
// Data structure

int main() {
   int n, m;
   cin >> n >> m;
   vector<int> u, v, w, a, b, ori;
   vector<set<int>> ed(n);
   auto make = [&](int from, int to, int wt, int ch1, int ch2) -> int {
      int result = sz(u);
      u.push_back(from);
      v.push_back(to);
      w.push_back(wt);
      a.push_back(ch1);
      b.push_back(ch2);
      ed[from].insert(result);
      ed[to].insert(result);
      ori.push_back(from == to ? to : -1);
      return result;
   };
   auto combine = [&](int e1, int e2, int common) -> int {
         pp("combine", e1, e2, common);
      ed[u[e1]].erase(e1);
      ed[v[e1]].erase(e1);
      ed[u[e2]].erase(e2);
      ed[v[e2]].erase(e2);
      pp(u[e1], v[e1], common);
      pp(u[e2], v[e2], common);
      int nU = (u[e1] ^ v[e1] ^ common);
      int nV = (u[e2] ^ v[e2] ^ common);
      int e = make(nU, nV, w[e1], e1, e2);
      if (nU == nV) {
         ed[nU].erase(e);
      }
      return e;
   };

   for (int i = 0; i < m; ++i) {
      int from, to, wt;
      cin >> from >> to >> wt;
      --from, --to;
      make(from, to, wt, -1, -1);
   }
   pp(u);
   vector<int> toCheck;
   for (int i = 0; i < n; ++i) {
      toCheck.push_back(i);
   }
   for (int _i = 0; _i < sz(toCheck); ++_i) {
      int i = toCheck[_i];
      pp("check", i, ed[i]);
      vector<int> prv = {-1, -1};
      set<int> s = ed[i];
      for (int j: s) {
         int &p = prv[w[j] - 1];
         if (p != -1) {
            int ne = combine(p, j, i);
            p = -1;
            toCheck.push_back(u[ne]);
            toCheck.push_back(v[ne]);
         } else {
            p = j;
         }
      }
   }
   pp(ed);

   vector<int> color(n);
   auto dfs = yc([&](auto rec, int cur, int c) -> void {
      if (color[cur]) {
         if (color[cur] != c) throw "gg";
         return;
      }
      color[cur] = c;
      for (int e: ed[cur]) {
         int nxt = cur ^ u[e] ^ v[e];
         rec(nxt, 3 - c);
      }
   });
   for (int i = 0; i < n; ++i) {
      if (!color[i]) {
         dfs(i, 1);
      }
   }
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j: ed[i]) {
         if (w[j] == 1) ++cnt;
      }
      if (cnt) ++ans;
   }

   pp(ed);
   vector<int> toDown;
   for (int i = 0; i < n; ++i) {
      for (int e: ed[i]) {
         ori[e] = (color[v[e]] == w[e]) ? v[e] : u[e];
      }
   }
   for (int i = 0; i < sz(u); ++i) {
      if (ori[i] != -1) toDown.push_back(i);
   }
   pp(u);
   pp(v);
   pp(w);
   pp(color);
   pp(a, b);
   pp(ori);
   for (int _i = 0; _i < sz(toDown); ++_i) {
      int i = toDown[_i];
      int aa = a[i], bb = b[i];
      if (aa == -1) continue;
      if (u[aa] == ori[i] || v[aa] == ori[i]) {
         swap(aa, bb);
      }
      int common = u[bb] ^ v[bb] ^ ori[i];
      ori[bb] = ori[i];
      ori[aa] = common;
      toDown.push_back(aa);
      toDown.push_back(bb);
   }
   pp(toDown);
   cout << ans << "\n";
   pp(ori);
   for (int i = 0; i < m; ++i) {
      cout << ((v[i] == ori[i]) ? 1 : 2);
   }
   cout << "\n";
   cout << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases