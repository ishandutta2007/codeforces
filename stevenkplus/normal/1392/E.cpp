// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
// int __fastio = fastio();
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ============= Solution ============= //
int main() {
   int T;
   T = 1;
   // cin >> T;
   for (int t = 1; t <= T; ++t) {
      int n;
      cin >> n;
      vector<vector<ll>> grid(n, vector<ll>(n));
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
            if (i % 2 == 1) {
               grid[i][j] = 1LL << (i + j);
            }
         }
      }
      for (auto v: grid) {
         for (auto i: v) {
            cout << i << " ";
         }
         cout << "\n";
      }
      cout.flush();

      int q;
      cin >> q;
      for (int t = 0; t < q; ++t) {
         ll x;
         cin >> x;
         int i = 0, j = 0;
         vector<pii> ans;
         ans.push_back(pii(i, j));
         for (int k = 1; k < 2 * n - 1; ++k) {
            if ((x >> k) & 1) {
               if (i % 2 == 0) {
                  ++i;
               } else {
                  ++j;
               }
            } else {
               if (i % 2 == 1) {
                  ++i;
               } else {
                  ++j;
               }
            }
            ans.push_back(pii(i, j));
         }
         for (pii p: ans) {
            cout << p.fi + 1 << " " << p.se + 1 << "\n";
         }
         cout.flush();
      }
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases