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

// cross (v[-1] - v[-2], p - v[-2])
ll cross(vector<pii> &v, pii p) {
  int k = sz(v);
  pii a = v[k - 2];
  pii b = v[k - 1];
  ll x1 = b.fi - a.fi;
  ll y1 = b.se - a.se;
  ll x2 = p.fi - a.fi;
  ll y2 = p.se - a.se;
  return x1 * y2 - x2 * y1;
}


int main() {
  while (true) {
    int n;
    cin >> n;
    if (!n) return 0;
    vector<string> grid(n);
    for (auto &s: grid) {
      cin >> s;
    }
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != '0') {
          v.push_back(pii(j + 1, n - i));
        }
      }
    }

    sort(v.begin(), v.end());
    pp(v);
    pii cur = v.front();
    v.erase(v.begin());
    vector<pii> upper, lower;
    upper.push_back(cur);
    lower.push_back(cur);
    for (auto p: v) {
      while (sz(upper) >= 2 && cross(upper, p) >= 0) {
        upper.pop_back();
      }
      while (sz(lower) >= 2 && cross(lower, p) <= 0) {
        lower.pop_back();
      }
      upper.push_back(p);
      lower.push_back(p);
    }

    vector<pii> upper2, lower2;
    for (int i = 1; i < sz(upper); ++i) {
      pii val = upper[i];
      if (upper[i].se <= upper[i - 1].se) {
        --val.fi;
      }
      --val.se;
      upper2.push_back(val);
    }

    for (int i = 0; i + 1 < sz(lower); ++i) {
      pii val = lower[i];
      if (lower[i].se < lower[i + 1].se) {
        --val.fi;
      }
      lower2.push_back(val);
    }
    pp(lower, lower2);
    vector<pii> ans;
    ans.push_back(lower2.front()); // lex min
    for (auto k: upper2) {
      if (sz(ans) > 0 && ans.back() == k) continue;
      ans.push_back(k);
    }
    reverse(lower2.begin(), lower2.end());
    for (auto k: lower2) {
      if (sz(ans) > 0 && ans.back() == k) continue;
      ans.push_back(k);
    }
    if (ans.back() == ans.front()) ans.pop_back();
    cout << sz(ans) << "\n";
    for (auto p: ans) {
      cout << p.fi << " " << p.se << "\n";
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
// - 4/8/20 typo -- forgot to change i -> j when copying var declarations x -> y (4 copies) [cf 690b1]