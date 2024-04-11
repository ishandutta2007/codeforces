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
#else
#define pp(...)
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

const int inf = 1000 << 20;
// =========== Solution ============= //

const int MAXN = 1111;
pii dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
string s, t;
int n, m;
pii getdp(int a, int b) {
  if (a > n || b > m) return pii(inf, 0);
  if (a == n && b == m) return pii(0, 0);
  pii &ret = dp[a][b];
  if (ret.se) return ret;
  ret = pii(inf, 0);
  if (s[a] == t[b]) {
    ret = getdp(a + 1, b + 1);
    ret.se = 4;
  } else {
    pii c1 = getdp(a + 1, b);
    c1.se = 1;
    pii c2 = getdp(a + 1, b + 1);
    c2.se = 2;
    pii c3 = getdp(a, b + 1);
    c3.se = 3;
    pii c = min(c1, min(c2, c3));
    ++c.fi;
    ret = c;
  }
  return ret;
}

int main() {
  cin >> s >> t;
  n = sz(s);
  m = sz(t);
  pii ans = getdp(0, 0);
  cout << ans.fi << "\n";
  pii cur = pii(0, 0);
  vector<string> out;
  while (cur.fi < n || cur.se < m) {
    pp(cur);
    stringstream ss;
    pii p = dp[cur.fi][cur.se];
    pp(p);
    if (p.se == 1) {
      ss << "DELETE " << cur.fi + 1;
      ++cur.fi;
    } else if (p.se == 2) {
      ss << "REPLACE " << cur.fi + 1 << " " << t[cur.se];
      ++cur.fi, ++cur.se;
    } else if (p.se == 3) {
      ss << "INSERT " << cur.fi + 1 << " " << t[cur.se];
      ++cur.se;
    } else if (p.se == 4) {
      ++cur.fi,
      ++cur.se;
    }
    string s = ss.str();
    out.push_back(s);
  }
  reverse(out.begin(), out.end());
  for (string s: out) {
    cout << s << "\n";
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