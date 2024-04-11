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

#define setmax(a, b) a = max(a, b)
// ============= Solution ============= //
int main() {
   int T;
   // cin >> T;
   T = 1;
   for (int t = 1; t <= T; ++t) {
      int n1, n2, n3;
      cin >> n1 >> n2 >> n3;
      vector<int> a(n1), b(n2), c(n3);
      for (int &i: a) cin >> i;
      for (int &i: b) cin >> i;
      for (int &i: c) cin >> i;
      sort(a.begin(), a.end(), greater<>());
      sort(b.begin(), b.end(), greater<>());
      sort(c.begin(), c.end(), greater<>());
#define ve vector
      ve<ve<ve<int>>> dp(n1 + 1, ve<ve<int>>(n2 + 1, ve<int>(n3 + 1)));
      int ans = 0;
      for (int i = 0; i <= n1; ++i) {
         for (int j = 0; j <= n2; ++j) {
            for (int k = 0; k <= n3; ++k) {
               for (int choice = 0; choice < 3; ++choice) {
                  int add;
                  int ni = i, nj = j, nk = k;
                  if (choice == 0) {
                     if (ni == n1 || nj == n2) continue;
                     add = a[ni++] * b[nj++];
                  } else if (choice == 1) {
                     if (ni == n1 || nk == n3) continue;
                     add = a[ni++] * c[nk++];
                  } else {
                     if (nj == n2 || nk == n3) continue;
                     add = b[nj++] * c[nk++];
                  }
                  setmax(dp[ni][nj][nk], dp[i][j][k] + add);
                  setmax(ans, dp[ni][nj][nk]);
               }
            }
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