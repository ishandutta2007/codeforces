// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
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


// ========== Solution ========== //

int main() {
  int n;
  cin >> n;
  if (n < 3) {
    cout << -1 << "\n"; return 0;
  }

  vector<vector<int>> ans(n, vector<int>(n));
  int cnt = 0;
  for (int i = n - 1; i >= 3; --i) {
    for (int j = 0; j <= i; ++j) {
      if (i % 2 == 0) ans[i][j] = ++cnt;
      else ans[j][i] = ++cnt;
    }
    for (int j = i - 1; j >= 0; --j) {
      if (i % 2 == 1) ans[i][j] = ++cnt;
      else ans[j][i] = ++cnt;
    }
  }

  vector<int> threeX({0, 1, 1, 2, 0, 1, 2, 2, 0});
  vector<int> threeY({0, 0, 2, 2, 2, 1, 1, 0, 1});
  for (int i = 0; i < 9; ++i) {
    ans[threeX[i]][threeY[i]] = ++cnt;
  }
  for (auto v: ans) {
    for (auto i: v) {
      cout << i << " ";
    }
    cout << "\n";
  }
}