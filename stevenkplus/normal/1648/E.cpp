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
// kruskal on input graph G_1 w/ smaller-into-larger DSU
// maintain vector<vector<int>> ccs of constituent components in G_2 (parallel kruskal on G_2)
// when join(a, b), also merge ccs[a] into ccs[b], merging where necessary

int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, m;
      cin >> n >> m;
      vector<int> par(n);
      vector<vector<int>> members(n);
      vector<vector<int>> components(n);
      vector<vector<int>> component_ids(n);
      vector<int> cpar(n);
      for (int i = 0; i < n; ++i) {
         par[i] = i;
         members[i].push_back(i);
         component_ids[i].push_back(i);
         components[i].push_back(i);
         cpar[i] = i;
      }

      vector<int> ans(m);
      vector<vector<pii>> queries(n);
      vector<pair<int, pii>> edges(m);
      vector<unordered_set<int>> ed(n);
      for (int i = 0; i < m; ++i) {
         int a, b, c;
         cin >> a >> b >> c; --a, --b;
         edges[i].fi = c;
         edges[i].se = pii(a, b);
         queries[a].push_back(pii(b, i));
         queries[b].push_back(pii(a, i));
         ed[a].insert(b);
         ed[b].insert(a);
      }
      auto check = [&](int x, int y, int w) -> int {
         bool ok = false;
         for (int i: components[x]) {
            for (int j: components[y]) {
               if (!ed[i].count(j)) {
                  ok = true;
                  break;
               }
            }
            if (ok) break;
         }
         if (!ok) return x;
         if (sz(components[x]) > sz(components[y])) {
            swap(x, y);
         }
         for (int i: components[x]) {
            for (pii p: queries[i]) {
               if (cpar[p.fi] == y) {
                  ans[p.se] = w;
               }
            }
         }
         pp(x, y);
         for (int i: components[x]) {
            cpar[i] = y;
            components[y].push_back(i);
         }
         components[x].clear();
         return y;
      };
      sort(edges.begin(), edges.end());
      for (auto p: edges) {
         int a = par[p.se.fi];
         int b = par[p.se.se];
         if (a == b) continue;
         if (sz(members[a]) > sz(members[b])) swap(a, b);
         // merge components
         for (int x: component_ids[a]) {
            int tot = 0;
            for (int y: component_ids[b]) {
               tot += sz(components[y]);
            }
            vector<int> to_merge;
            int ox = x;
            for (int y: component_ids[b]) {
               x = check(x, y, p.fi);
            }
            component_ids[b].push_back(ox);
         }

         vector<int> nc;
         for (int x: component_ids[b]) {
            if (sz(components[x])) {
               nc.push_back(x);
            }
         }
         component_ids[a].clear();
         component_ids[b] = nc;

         // merge par & members
         for (int i: members[a]) {
            par[i] = b;
            members[b].push_back(i);
         }
         members[a].clear();
      }
      for (int i: ans) cout << i << " ";
      cout << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases