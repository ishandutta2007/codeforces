// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "{"; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
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
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

// =========== Solution ============= //

int n;
vector<string> grid;
int get(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= n) return 0;
  return grid[x][y] == '4';
}

int main() {
  cin >> n;
  grid = vector<string>(n);
  for (auto &s: grid) {
    cin >> s;
  }

  int tot = 0, xmin = n, ymin = n, xmax = 0, ymax = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '4') {
        xmin = min(xmin, i);
        xmax = max(xmax, i);
        ymin = min(ymin, j);
        ymax = max(ymax, j);
        ++tot;
      }
    }
  }
  if ((xmax - xmin + 1) * (ymax - ymin + 1) != tot) {
    cout << "No\n";
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch;
      if (grid[i][j] == '4') {
        ch = '4';
      } else {
        int sides = get(i + 1, j) + get(i - 1, j) + get(i, j + 1) + get(i, j - 1);
        int corners = get(i + 1, j + 1) + get(i - 1, j + 1) + get(i + 1, j - 1) + get(i - 1, j - 1);
        if (sides) ch = '2';
        else if (corners) ch = '1';
        else ch = '0';
      }
      if (grid[i][j] != ch) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
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
// - 4/8/20 typo -- forgot to change i -> j when copying var declarations x -> y (4 copies) [cf 690b1]