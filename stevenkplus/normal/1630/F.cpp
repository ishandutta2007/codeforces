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

const int MAXN = 100100;

using vi = vector<int>;
#define rep(i, a, n) for(int i = (a); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
   if (A[a] != L) return 0;
   A[a] = -1;
   for (int b : g[a]) if (B[b] == L + 1) {
      B[b] = 0;
      if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
         return btoa[b] = a, 1;
   }
   return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
   int res = 0;
   vi A(g.size()), B(btoa.size()), cur, next;
   for (;;) {
      fill(all(A), 0);
      fill(all(B), 0);
      /// Find the starting nodes for BFS (i.e. layer 0).
      cur.clear();
      for (int a : btoa) if(a != -1) A[a] = -1;
      rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
      /// Find all layers using bfs.
      for (int lay = 1;; lay++) {
         bool islast = 0;
         next.clear();
         for (int a : cur) for (int b : g[a]) {
            if (btoa[b] == -1) {
               B[b] = lay;
               islast = 1;
            }
            else if (btoa[b] != a && !B[b]) {
               B[b] = lay;
               next.push_back(btoa[b]);
            }
         }
         if (islast) break;
         if (next.empty()) return res;
         for (int a : next) A[a] = lay;
         cur.swap(next);
      }
      /// Use DFS to scan for augmenting paths.
      rep(a,0,sz(g))
         res += dfs(a, 0, g, btoa, A, B);
   }
}

// ============= Solution ============= //
int main() {
   int T; cin >> T;
   vector<vector<int>> fac(MAXN);
   for (int i = 1; i < MAXN; ++i) {
      for (int j = 2 * i; j < MAXN; j += i) {
         fac[j].push_back(i);
      }
   }
   while (T--) {
      int n; cin >> n;
      vector<vi> g(2 * n);
      vector<int> v(n); for (int &i: v) cin >> i;
      map<int, int> mp;
      for (int i = 0; i < n; ++i) mp[v[i]] = i;
      for (int i = 0; i < n; ++i) {
         for (int j: fac[v[i]]) {
            if (mp.count(j)) {
               int k = mp[j];
               g[i].push_back(k);
               g[i + n].push_back(k + n);
            }
         }
         g[i].push_back(i + n);
      }
      vector<int> btoa(2 * n, -1);
      pp(g);
      // pp(hopcroftKarp(g, btoa));
      int ans = n - (2 * n - hopcroftKarp(g, btoa));
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