// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

// =========== Solution ============= //

vector<vector<ll>> alldp[12];

ll get(int b, ll x) {
  vector<vector<ll>> &dp = alldp[b];
  vector<int> digits;
  while (x) {
    digits.push_back(x % b);
    x /= b;
  }
  reverse(digits.begin(), digits.end());
  pp(digits);
  vector<int> counts(b);
  ll ans = 0;
  for (int i = 0; i < sz(digits); ++i) {
    for (int j = 0; j < digits[i]; ++j) {
      if (i == 0 && j == 0) continue; // forbid leading 0s
      ++counts[j];
      int singles = 0;
      for (int k = 0; k < b; ++k) {
        if (counts[k] % 2 == 1) ++singles;
      }
      --counts[j];

      pp(i, j, singles, sz(digits) - i - 1);
      ll dpval = dp[singles][sz(digits) - i - 1];
      pp(dpval);
      ans += dp[singles][sz(digits) - i - 1];
    }
    ++counts[digits[i]];
  }
  for (int i = 1; i < sz(digits); ++i) {
    ans += (b - 1) * dp[1][i - 1];
  }
  return ans;
}

const ll MAXN = 1E18;
// number of digits of a in base b
int log(ll a, int b) {
  int ret = 0;
  while (a) {
    ++ret;
    a /= b;
  }
  return ret;
}

int main() {
  for (int b = 2; b <= 10; ++b) {
    vector<vector<ll>> &dp = alldp[b];
    int n = log(MAXN, b) + 1;
    pp(n);
    dp = vector<vector<ll>>(n, vector<ll>(n));
    dp[0][0] = 1;
    for (int j = 1; j < n; ++j) {
      for (int i = 0; i < n; ++i) {
        if (i + 1 < n)
          dp[i][j] += dp[i + 1][j - 1] * (b - i);
        if (i - 1 >= 0)
          dp[i][j] += dp[i - 1][j - 1] * i;
      }
    }
  }

  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int b;
    ll l, r;
    cin >> b >> l >> r;
    ++r;
    ll ans = get(b, r) - get(b, l);
    pp(b, l, r);
    cout << ans << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - initialize & re-initialize efficiently between test cases
//
// history of bugs
// - 3/28/20 forgot to initialize set with dummy node (n) [cf 1136e]
// - 3/28/20 array bounds (map was size MAXN instead of MAXK) [cf 1210b]
// - 3/29/20 array bounds ([MAXN][MAXN][4] -> [MAXN][MAXN * 2][4]) [cf 1051d]
// - 3/29/20 special cases (answer cannot be empty string) [cf 848a]
// - 3/29/20 special case / bad initialization of (ans, ansi) when backtracking [cf 733f]
// - 3/30/20 special case / "0" has length 0 in binary [cf 748b]
// - 4/2/20 fakesolve -- setup of dp states missed possible transitions / solutions [cf 771D]
// - 4/2/20 fakesolve -- cant count inversions in linear time, misunderstand structure of problem [cf 771D]
// - 4/3/20 (TLE) re-initialization was too slow [cf 1329 D]
// - 4/3/20 (WA) bottom-up segtree query didn't handle [0, n) correctly
// - 4/5/20 array bounds -- two different array sizes needed [cf 18d]
// - 4/5/20 fakesolve -- greedy sol was wrong,  needed dp [cf 18d]
// - 4/6/20 fakesolve -- tried to do LIS backtracking incorrectly w/ greedy approach, needed true backtracking [cf 650d]
// - 4/6/20 array bounds -- indexing with count into vector of size n; needs to be n + 1
// - 4/7/20 typo -- forgot to change i -> j when copying var declarations x -> y (4 copies) [cf 690b1]
// - 4/8/20 implementation error -- forgot to iterate in sorted order of x [cf 1045g]
// - 4/8/20 plane sweep implementation error -- insertion & removal orders are distinct (x_i & x_i + r_i) [cf 1045g]
// - 4/8/20 inf not big enough -- 1000 << 20 vs 1 billion + 1 billion [cf 1045g]
// - 4/8/20 n ffts wayyy too slow (nlog^2n, n = 2^20, time limit = 1s) [cf 1227f2]
// - 4/8/20 int overflow (multiplied j * count[j] without LL, when adding to ll) [cf 804d]
// - 4/8/20 implementation error -- forgot to dfs again (a 3rd time) after finding both ends of diameter [cf 804d]
// - 4/8/20 typo -- cur.fi < n && cur.se < n <-- should be m
// - 4/10/20 implementation error -- need to erase before inserting into pdbs::tree [1093e]
// - 4/10/20 typo -- forgot to change n + 1 to m + 1 when fixing sliding window to be over edges instead of nodes [cf 901c]
// - 4/10/20 typo -- implementation error -- messed up dfs cycle detection; need to mark edges as vis instead of nodes / use a real algo [cf 901c]
// - 4/10/20 turns out i misread the problem and it's actually querying nodes, not edges
// - 4/10/20 typo -- s/m/n again in if (r < m && ...)
// - 4/10/20 int overflow -- map<int, int> instead of map<ll, int> (elements were from vector<ll>)