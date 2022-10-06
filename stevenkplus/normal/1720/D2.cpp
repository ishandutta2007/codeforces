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
struct node;
ostream& operator<<(ostream &os, const node &node);
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

// ============= Solution ============= //
int main() {
   int T;
   cin >> T;
   vector<vector<int>> dp2(60, vector<int>(1 << 17)); // i, k => (k, i[k], v[i] >> (k - 1)) >= dp[i]
   while (T--) {
      int n;
      cin >> n;
      vector<int> v(n);
      for (int &i: v) cin >> i;
      for (int i = 0; i < n; ++i) {
         v[i] ^= i;
      }
      vector<int> par = {0, 0}, ch = {0, 0};
      auto getNode = [&](int x) -> int {
         int cur = 1;
         for (int i = 29; i >= 0; --i) {
            if (!ch[cur]) {
               ch[cur] = sz(par);
               par.push_back(cur);
               par.push_back(cur);
               ch.push_back(0);
               ch.push_back(0);
            }
            cur = ch[cur];
            if ((x >> i) & 1) {
               cur ^= 1;
            }
         }
         return cur;
      };
      for (int i = 0; i < n; ++i) {
         getNode(v[i]);
      }

      pp(par);
      for (int i = 0; i < n; ++i) {
         pp(getNode(v[i]));
         pp(par[getNode(v[i])]);
      }
      vector<vector<int>> dp(2, vector<int>(sz(par)));
      int ans = 0;
      for (int i = 0; i < n; ++i) {
         int cur = getNode(v[i]);
         int val = 0;
         for (int k = 0; k < 30; ++k) {
            // for all j s.t. (i ^ j)[k] = x and (v[i] ^ v[j])[k] = 1 and (v[i] ^ v[j]) >> (k + 1) == 0,
            // where x = 1 if v[i][k] < v[j][k] and x = 0 otherwise
            // find max dp[j]

            val = max(val, dp[(1 ^ ((i ^ v[i]) >> k)) & 1][cur ^ 1]);
            cur = par[cur];
            // pp(val);
         }
         val += 1;
         cur = getNode(v[i]);
         for (int k = 0; k < 30; ++k) {
            dp[(i >> k) & 1][cur] = max(dp[(i >> k) & 1][cur],  val);
            cur = par[cur];
         }
         ans = max(ans, val);
      }
      cout << ans << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases