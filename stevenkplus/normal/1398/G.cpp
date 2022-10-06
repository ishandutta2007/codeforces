// AVX-enabled std::bitset Pragmas (before #includes!)
// - bitset<200000> takes ~ 1ms per 1000 operations on GNU C++14 & GNU C++17
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

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
#define yc y_combinator;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

using BS = bitset<1 << 18>;

#define setmax(a, b) a = max(a, b)
// ============= Solution ============= //
int main() {
   int T;
   // cin >> T;
   T = 1;
   for (int t = 1; t <= T; ++t) {
      int n, x, y;
      cin >> n >> x >> y;
      BS bs;
      vector<int> v(n + 1);
      for (int &i: v) cin >> i;
      for (int i: v) bs[i] = 1;
      int MAXN = 1E6 + 1;
      vector<bool> vis(MAXN);
      for (int i = 1; i < (1 << 18) &&  2 * (i + y) < MAXN; ++i) {
         BS msk = bs & (bs << i);
         vis[2 * (i + y)] = msk.any();
      }
      vector<int> ans(MAXN, -1);
      for (int i = 1; i < MAXN; ++i) {
         if (!vis[i]) continue;
         for (int j = i; j < MAXN; j += i) {
            ans[j] = i;
         }
      }
      int q;
      cin >> q;
      for (int i = 0; i < q; ++i) {
         int len;
         cin >> len;
         cout << ans[len] << " ";
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