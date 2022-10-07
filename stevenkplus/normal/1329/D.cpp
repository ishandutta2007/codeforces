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

const int MAXN = 1 << 18;
const int MAXC = 222;
int cnts[MAXC];

int val() {
  int tot = 0;
  int mx = 0;
  for (char c = 'a'; c <= 'z'; ++c) {
    mx = max(mx, cnts[int(c)]);
    tot += cnts[int(c)];
  }
  return max((tot + 1) / 2, mx);
}

int v1;
bool can(char a, char b) {
  if (a == b) return false;
  --cnts[int(a)];
  --cnts[int(b)];
  int v2 = val();
  ++cnts[int(a)];
  ++cnts[int(b)];
  return v2 + 1 == v1;
}

int seg[MAXN * 2];
int SEGZ;

int ask(int x) {
  int ans = 0;
  for (int i = x + SEGZ, j = SEGZ; i > j; i /= 2, j /= 2) {
    if (i % 2 == 1) {
      ans += seg[i - 1];
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    memset(cnts, 0, sizeof(cnts));
    string s;
    cin >> s;
    int n = sz(s);
    for (int i = 0; i + 1 < n; ++i) {
      if (s[i] == s[i + 1]) ++cnts[int(s[i])];
    }
    vector<pii> stk;
    vector<pii> ans;
    v1 = val();
    for (int i = 0; i + 1 < n; ++i) {
      if (s[i] == s[i + 1]) {
        if (!stk.empty() && can(stk.back().fi, s[i])) {
          --cnts[stk.back().fi];
          --cnts[int(s[i])];
          v1 = val();
          ans.push_back(pii(stk.back().se, i + 1));
          stk.pop_back();
        } else {
          stk.push_back(pii(s[i], i + 1));
        }
      }
    }
    for (auto k: stk) {
      ans.push_back(pii(0, k.se));
    }
    ans.push_back(pii(0, n));
    pp(ans);

    SEGZ = 1;
    while (SEGZ <= n) SEGZ *= 2;
    for (int i = 0; i < n; ++i) {
      seg[SEGZ + i] = 1;
    }
    for (int i = SEGZ - 1; i > 0; --i) {
      seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
    cout << sz(ans) << "\n";
    for (auto p: ans) {
      int a = ask(p.fi);
      int b = ask(p.se);
      seg[p.fi + SEGZ] -= b - a;
      for (int i = (p.fi + SEGZ) / 2; i > 0; i /= 2) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
      }
      cout << a + 1 << " " << b << "\n";
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