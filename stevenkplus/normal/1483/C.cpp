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

// ============= Solution ============= //
int main() { // dobby is a free elf
   int T;
   // cin >> T;
   T = 1;
   while (T--) {
      int n;
      cin >> n;
      vector<int> h(n), B(n);
      for (int &i: h) cin >> i;
      for (int &i: B) cin >> i;
      vector<int> nxt(n + 1, n), prv(n + 1, n);
      for (int i = 0; i + 1 < n; ++i) {
         nxt[i] = i + 1;
         prv[i + 1] = i;
      }

      vector<pii> byH(n);
      for (int i = 0; i < n; ++i) {
         byH[i] = pii(h[i], i);
      }
      sort(byH.begin(), byH.end());
      reverse(byH.begin(), byH.end());

      vector<vector<int>> children(n + 1);
      vector<ll> dp(n), dp1(n), dp2(n);

      vector<bool> leftmax(n), rightmax(n);
      int curmin = n + 1;
      for (int i = 0; i < n; ++i) {
         if (h[i] < curmin) {
            curmin = h[i];
            leftmax[i] = true;
         }
      }
      curmin = n + 1;
      for (int i = n - 1; i >= 0; --i) {
         if (h[i] < curmin) {
            curmin = h[i];
            rightmax[i] = true;
         }
      }
      int last = -1;
      for (pii p: byH) {
         int i = p.se;
         int a = prv[i], b = nxt[i];
         int par = -1;
         pp(i, a, b);
         if (a != n && (b == n || h[a] > h[b])) {
            par = a;
         }
         if (b != n && (a == n || h[a] < h[b])) {
            par = b;
         }
         if (par != -1) children[par].push_back(i);
         nxt[prv[i]] = nxt[i];
         prv[nxt[i]] = prv[i];
         dp[i] = B[i];
         int cc = -1;
         pp(i, B[i], children[i]);
         for (int ch: children[i]) {
            dp[i] += max(0LL, dp[ch]);
         }
         for (int ch: children[i]) {
            if (ch < i && !rightmax[i]) {
               dp[i] = max(dp[i], dp[ch]);
            }
            if (ch > i && !leftmax[i]) {
               dp[i] = max(dp[i], dp[ch]);
            }
         }
         if (par != -1 && cc != -1) dp[i] = max(dp[i], dp[cc]);
         pp(i, dp[i]);
         last = i;
      }

      pp(dp);
      cout << dp[last] << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases