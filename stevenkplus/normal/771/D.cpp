// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { string sep = "{"; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define pp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

const int MAXN = 80;
const int inf = 1000 << 20;
int DP[MAXN][MAXN][MAXN][2]; // DP[tot][vs][ks][w]
int cnts[3][MAXN];

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> pos[3];
  pp("help");
  for (int i = 0; i < n; ++i) {
    int type;
    if (s[i] == 'V') type = 0;
    else if (s[i] == 'K') type = 1;
    else type = 2;
    pos[type].push_back(i);
    for (int j = 0; j < 3; ++j) {
      cnts[j][i + 1] = cnts[j][i];
    }
    ++cnts[type][i + 1];
  }
  pp("help");

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        for (int w = 0; w < 2; ++w) {
          DP[i][j][k][w] = inf;
        }
      }
    }
  }

  DP[0][0][0][1] = 0;
  int ans = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        for (int w = 0; w < 2; ++w) {
          if (DP[i][j][k][w] < inf) pp(i, j, k, w, DP[i][j][k][w]);
          for (int nxt = 0; nxt < 3; ++nxt) {
            int used[] = {j, k, i - j - k};
            if (used[nxt] >= pos[nxt].size()) continue;
            if (nxt == 1 && w == 0) {
              continue;
            }
            int p = pos[nxt][used[nxt]];
            int inversions = 0;
            for (int t = 0; t < 3; ++t) {
              inversions += max(0, cnts[t][p] - used[t]);
            }
            int v = DP[i][j][k][w] + inversions;
            max(0, pos[nxt][used[nxt]] - i);

            ++used[nxt];
            int nj = used[0];
            int nk = used[1];
            int &nv = DP[i + 1][nj][nk][nxt > 0];
            if (v < inf) pp(i + 1, nj, nk, nxt > 0, v);
            nv = min(nv, v);
            if (i + 1 == n) {
              ans = min(ans, v);
            }
          }
        }
      }
    }
  }
  cout << ans << "\n";
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