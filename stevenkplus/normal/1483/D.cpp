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

int _gcd(int a, int b) {
   if (!a) return b;
   return _gcd(b % a, a);
}
typedef pair<int, pii> plii;
const int inf = 1000 << 20;

// ============= Solution ============= //
int main() { // dobby is a free elf
   int T;
   // cin >> T;
   T = 1;
   while (T--) {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> dst(n, vector<int>(n, inf));
      for (int i = 0; i < n; ++i) {
         dst[i][i] = 0;
      }
      vector<pair<pii, int>> edges(m);
      for (int i = 0; i < m; ++i) {
         cin >> edges[i].fi.fi >> edges[i].fi.se >> edges[i].se;
         --edges[i].fi.fi;
         --edges[i].fi.se;

      }
      for (auto p: edges) {
         int i = p.fi.fi, j = p.fi.se, k = p.se;
         dst[i][j] = dst[j][i] = k;
      }
      for (int k = 0; k < n; ++k) {
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
               dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
            }
         }
      }

      vector<vector<int>> slack(n, vector<int>(n, -1));
      int q;
      cin >> q;
      for (int i = 0; i < q; ++i) {
         int u, v, l;
         cin >> u >> v >> l;
         --u, --v;
         slack[u][v] = slack[v][u] = max(slack[u][v], l - dst[u][v]);
      }
      for (int rep = 0; rep < 2; ++rep) {
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
               for (int k = 0; k < n; ++k) {
                  int nslk = slack[i][j] + dst[i][j] - dst[i][k] - dst[k][j];
                  if (nslk > slack[k][j]) {
                     slack[k][j] = nslk;
                  }
                  if (nslk > slack[i][k]) {
                     slack[i][k] = nslk;
                  }
               }
            }
         }
      }

      int ans = 0;
      for (auto p: edges) {
         int i = p.fi.fi, j = p.fi.se;
         if (p.se - dst[i][j] <= slack[i][j]) {
            ++ans;
         }
      }

      cout << ans << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases