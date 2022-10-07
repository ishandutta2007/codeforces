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

const int inf = 1000 << 20;

// =========== Solution ============= //

const int MAXN = 1 << 22;

int ar[MAXN];
int h, g;

bool can(int i) {
  while (i < (1 << g)) {
    pii p = max(pii(ar[i * 2], i * 2), pii(ar[i * 2 + 1], i * 2 + 1));
    if (p.fi == 0) return false;
    i = p.se;
  }
  return true;
}

void go(int i) {
  while (i < (1 << (h - 1))) {
    pii p = max(pii(ar[i * 2], i * 2), pii(ar[i * 2 + 1], i * 2 + 1));
    if (p.fi == 0) break;
    ar[i] = p.fi;
    i = p.se;
  }
  ar[i] = 0;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> h >> g;
    ll sum = 0;
    for (int i = 1; i < (1 << h); ++i) {
      cin >> ar[i];
      sum += ar[i];
      pp(i, ar[i]);
    }
    vector<int> ans;
    for (int i = 1; i < (1 << g); ++i) {
      while (can(i)) {
        ans.push_back(i);
        pp(i, ar[i]);
        sum -= ar[i];
        go(i);
      }
    }
    cout << sum << "\n";
    for (int i: ans) {
      cout << i << " ";
    }
    cout << "\n";
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