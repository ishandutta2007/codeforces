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
#define sub_to_errichto main
// =========== Book ============ //

const int inf = 1000 << 20;

// ============= Solution ============= //
int sub_to_errichto() { // fml
   int n, m;
   cin >> n >> m;
   vector<vector<int>> adj(n, vector<int>(n, inf));
   for (int i = 0; i < m; ++i) {
      int a, b, x;
      cin >> a >> b >> x; --a, --b;
      adj[a][b] = adj[b][a] = 1;
      if (x == 1) {
         adj[b][a] = -1;
      }
   }
   for (int i = 0; i < n; ++i) {
      adj[i][i] = 0;
   }
   for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
         }
      }
   }
   string ans = "YES";

   // check neg cycle
   for (int i = 0; i < n; ++i) {
      if (adj[i][i] < 0) {
         ans = "NO";
      }
   }

   // find the max dist & check bipartite
   int best = 0, maxDist = -1;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         for (int k = 0; k < n; ++k) {
            if ((adj[i][j] + adj[i][k] + adj[j][k]) % 2 == 1) {
               ans = "NO";
            }
         }
         if (adj[i][j] > maxDist) {
            best = i;
            maxDist = adj[i][j];
         }
      }
   }

   cout << ans << "\n";
   if (ans == "YES") {
      cout << maxDist << "\n";
      for (int i = 0; i < n; ++i) {
         cout << adj[best][i] << " ";
      }
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