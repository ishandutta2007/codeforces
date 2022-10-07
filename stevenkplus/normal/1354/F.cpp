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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

const int inf = 1000 << 20;
const ll infl = 1LL << 60;

// ============= Solution ============= //

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<pii> ord(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      ord[i] = pii(b[i], i);
    }
    sort(ord.begin(), ord.end());
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, infl));
    vector<vector<int>> trace(k + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    for (int cnt = 0; cnt <= k; ++cnt) {
      for (int i = 0; i < n; ++i) {
        int j = ord[i].se;
        if (dp[cnt][i] < dp[cnt][i + 1]) {
          dp[cnt][i + 1] = dp[cnt][i];
          trace[cnt][i + 1] = 0;
        }
        if (cnt < k) {
          ll cost = (k - 1 - cnt) * b[j] - a[j];
          if (dp[cnt][i] + cost < dp[cnt + 1][i + 1]) {
            dp[cnt + 1][i + 1] = dp[cnt][i] + cost;
            trace[cnt + 1][i + 1] = 1;
          }
        }
      }
    }
    pp(trace);
    vector<int> take(n);
    int cur = k;
    for (int i = n - 1; i >= 0; --i) {
      pp(i, cur);
      if (trace[cur][i + 1]) {
        take[i] = cur;
        --cur;
      }
    }
    pp(take);

    cout << n + n - k << "\n";
    for (int i = 0; i < n; ++i) {
      int j = ord[i].se + 1;
      if (take[i] && take[i] < k) {
        cout << j << " ";
      }
    }

    for (int i = 0; i < n; ++i) {
      int j = ord[i].se + 1;
      if (!take[i]) {
        cout << j << " " << -j << " ";
      }
    }

    for (int i = 0; i < n; ++i) {
      int j = ord[i].se + 1;
      if (take[i] == k) {
        cout << j;
      }
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