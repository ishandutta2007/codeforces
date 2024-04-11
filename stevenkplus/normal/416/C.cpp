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

typedef pair<int, pii> piii;

// =========== Solution ============= //

int main() {
  int n;
  cin >> n;
  vector<piii> reqs;
  for (int i = 0; i < n; ++i) {
    int c, p;
    cin >> c >> p;
    reqs.push_back(piii(p, pii(i + 1, c)));
  }
  sort(reqs.begin(), reqs.end());
  reverse(reqs.begin(), reqs.end());

  int k;
  cin >> k;
  set<pii> tables;
  for (int i = 0; i < k; ++i) {
    int r;
    cin >> r;
    tables.insert(pii(r, i + 1));
  }
  int sum = 0;
  vector<pii> ans;
  for (auto req: reqs) {
    auto p = tables.lower_bound(pii(req.se.se, 0));
    if (p != tables.end()) {
      sum += req.fi;
      ans.push_back(pii(req.se.fi, p->se));
      tables.erase(p);
    }
  }
  pp(reqs);

  cout << ans.size() << " " << sum << "\n";
  for (auto p: ans) {
    cout << p.fi << " " << p.se << "\n";
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