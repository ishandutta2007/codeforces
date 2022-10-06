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

// ============= Solution ============= //
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, m; cin >> n >> m;
      vector<int> deadlines(n);
      for (int &i: deadlines) cin >> i;
      vector<int> e(m), t(m), vp(m);
      for (int i = 0; i < m; ++i) cin >> e[i] >> t[i] >> vp[i], --e[i];

      vector<vector<int>> opts(n);
      for (int i = 0; i < m; ++i) opts[e[i]].push_back(i);
      vector<vector<int>> ans(n);
      vector<ll> anst(n);
      const ll infl = 1LL << 60;
      for (int i = 0; i < n; ++i) {
         int nc = sz(opts[i]);
         vector<vector<ll>> dp(nc + 1, vector<ll>(101, infl));
         vector<vector<int>> trace(nc + 1, vector<int>(101, -1));
         dp[0][0] = 0;
         for (int j = 0; j < nc; ++j) {
            dp[j + 1] = dp[j];
            trace[j + 1] = trace[j];
            for (int p = 0; p < 100; ++p) {
               int np = min(100, p + vp[opts[i][j]]);
               if (dp[j][p] + t[opts[i][j]] < dp[j + 1][np]) {
                  dp[j + 1][np] = dp[j][p] + t[opts[i][j]];
                  trace[j + 1][np] = j;
               }
            }
            for (int p = 99; p >= 0; --p) {
               if (dp[j + 1][p] > dp[j + 1][p + 1]) {
                  dp[j + 1][p] = dp[j + 1][p + 1];
                  trace[j + 1][p] = trace[j + 1][p + 1];
               }
            }
         }
         int j = nc;
         int cur = 100;
         while (cur > 0) {
            j = trace[j][cur];
            if (j == -1) {
               anst[i] = infl;
               break;
            }
            ans[i].push_back(opts[i][j]);
            anst[i] += t[opts[i][j]];
            cur -= vp[opts[i][j]];
         }
      }

      ll sumt = 0;
      bool ok = true;
      for (int i = 0; i < n; ++i) {
         sumt += anst[i];
         if (sumt > deadlines[i]) {
            ok = false;
            break;
         }
      }
      if (!ok) cout << "-1\n";
      else {
         vector<int> ans2;
         for (auto v: ans) {
            for (int i: v) ans2.push_back(i);
         }
         cout << sz(ans2) << "\n";
         for (int i: ans2) cout << i + 1 << " ";
            cout << "\n";
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