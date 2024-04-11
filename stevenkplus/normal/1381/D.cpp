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
   for (int t = 1; t <= T; ++t) {
      int n, a, b;
      cin >> n >> a >> b;
      --a, --b;
      vector<vector<int>> ed(n);
      for (int i = 0; i < n - 1; ++i) {
         int u, v;
         cin >> u >> v;
         --u, --v;
         ed[u].push_back(v);
         ed[v].push_back(u);
      }
      auto getPath = [&]() -> vector<int> {
         vector<int> par(n);
         auto dfs = yc([&](auto dfs, int cur, int prv = -1) -> void {
            par[cur] = prv;
            for (int nxt: ed[cur]) if (nxt != prv) {
               dfs(nxt, cur);
            }
         });
         dfs(a);
         vector<int> res;
         int cur = b;
         while (cur != -1) {
            res.push_back(cur);
            cur = par[cur];
         }
         return res;
      };

      vector<int> top = getPath();
      int k = sz(top);
      vector<bool> isTop(n), ok(n);
      vector<int> height(n);
      for (int i: top) {
         isTop[i] = true;
      }

      auto dfs = yc([&](auto dfs, int cur, int prv = -1) -> void {
         int cnt = 0;
         for (int nxt: ed[cur]) {
            if (nxt == prv || isTop[nxt]) continue;
            dfs(nxt, cur);
            if (height[nxt] >= k - 1) {
               ++cnt;
            }
            height[cur] = max(height[cur], height[nxt]);
            ok[cur] = ok[cur] || ok[nxt];
         }
         ok[cur] = ok[cur] || cnt >= 2;
         ++height[cur];
      });
      for (int i: top) {
         dfs(i);
      }
      auto fixTopOks = [&]() -> void {
         vector<int> leftHeight(k), rightHeight(k);
         for (int i = 0; i + 1 < k; ++i) {
            leftHeight[i + 1] = max(leftHeight[i] + 1, height[top[i]]);
         }
         for (int i = k - 1; i > 0; --i) {
            rightHeight[i - 1] = max(rightHeight[i] + 1, height[top[i]]);
         }
         for (int i = 0; i < k; ++i) {
            if (1 + leftHeight[i] >= k && 1 + rightHeight[i] >= k && height[top[i]] >= k) {
               ok[top[i]] = true;
            }
         }
      };
      pp("Before fix", ok);
      fixTopOks();
      pp("After fix", ok);

      string ans = "NO";
      int left = 1, right = 1;
      auto addLeft = [&](int i) -> void {
         if (ok[top[i]]) ans = "YES";
         int val = min(k, height[top[i]] - i);
         right = max(right, val);
      };
      auto addRight = [&](int i) -> void {
         if (ok[top[k - 1 - i]]) ans = "YES";
         int val = min(k, height[top[k - 1 - i]] - i);
         left = max(left, val);
      };
      int l = 0, r = 0;
      while (l < left || r < right) {
         if (l < left) addLeft(l++);
         else addRight(r++);
      }

      pp(top);
      pp(height);
      pp(ok);
      pp(ok);

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