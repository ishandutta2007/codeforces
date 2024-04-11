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

const int MAXN = 210;
pii DP[10][10][MAXN][MAXN];

vector<pii> get(int n) {
  vector<pii> res;
  for (int i = 0; i <= n - 2; ++i) {
    res.push_back(pii(i, n));
    res.push_back(pii(n, i));
  }
  for (int i = n + 1; i < MAXN; ++i) {
    res.push_back(pii(i, i - 2));
    res.push_back(pii(i - 2, i));
  }
  return res;
}

pii no;
int main() {
  vector<pii> scores25 = get(25), scores15 = get(15);
  DP[0][0][0][0] = pii(1, 0);
  for (int setsA = 0; setsA < 3; ++setsA) {
    for (int setsB = 0; setsB < 3; ++setsB) {
      vector<pii> &scores = setsA + setsB == 4 ? scores15 : scores25;
      for (int pointsA = 0; pointsA < MAXN; ++pointsA) {
        for (int pointsB = 0; pointsB < MAXN; ++pointsB) {
          if (DP[setsA][setsB][pointsA][pointsB] == no) continue;
          // try all game scores -- ~400 of them
          for (pii p: scores) {
            int npA = pointsA + p.fi;
            int npB = pointsB + p.se;
            int nsA = setsA + (p.fi > p.se ? 1 : 0);
            int nsB = setsB + (p.fi < p.se ? 1 : 0);
            if (npA < MAXN && npB < MAXN) {
              DP[nsA][nsB][npA][npB] = p;
            }
          }
        }
      }
    }
  }

  vector<pii> order({ {3, 0}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 3} });
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    pp(a, b);
    pii matchscore;
    for (pii p: order) {
      if (DP[p.fi][p.se][a][b] != no) {
        matchscore = p;
        break;
      }
    }
    pp(matchscore);
    if (matchscore == no) {
      cout << "Impossible\n";
    } else {
      cout << matchscore.fi << ":" << matchscore.se << "\n";
      vector<pii> games;
      pii cur(a, b);
      while (cur != no) {
        pp(matchscore, cur);
        pii g = DP[matchscore.fi][matchscore.se][cur.fi][cur.se];
        pp(g);
        games.push_back(g);
        if (g.fi > g.se) --matchscore.fi;
        else --matchscore.se;
        cur.fi -= g.fi;
        cur.se -= g.se;
      }
      reverse(games.begin(), games.end());
      for (pii g: games) {
        cout << g.fi << ":" << g.se << " ";
      }
      cout << "\n";
    }
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