// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
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

// CURRENT STREAK (fun level): 3 AC in a row
// CURRENT STREAK (easy level): 3 AC in a row
// CURRENT STREAK (medium level): 0 AC in a row

const ll infl = 1LL << 60;
// dp[i][k]: min cost of buying k items for the subproblem corresponding to subtree of i
const int MAXN = 5010;
vector<ll> dp[MAXN][2]; // DP[i][k][x] -- x is whether or not you can apply coupon to i (root)
ll C[MAXN];
ll D[MAXN];
int par[MAXN];


void mergeinto(vector<ll> &v, vector<ll> &w) {
  vector<ll> vw(v.size() + w.size() - 1);
  for (int i = 0; i < vw.size(); ++i) {
    vw[i] = infl;
  }
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < w.size(); ++j) {
      vw[i + j] = min(vw[i + j], v[i] + w[j]);
    }
  }
  w = vw;
}

void mininto(vector<ll> &v, vector<ll> &w) {
  for (int i = 0; i < v.size(); ++i) {
    w[i] = min(w[i], v[i]);
  }
}


int main() {
  int n, b;
  cin >> n >> b;
  for (int i = 0; i < n; ++i) {
    cin >> C[i] >> D[i];
    if (i > 0) {
      cin >> par[i];
      --par[i];
    }
    dp[i][0].push_back(0);
    dp[i][1].push_back(infl);
    dp[i][0].push_back(C[i]);
    dp[i][1].push_back(C[i] - D[i]);
  }

  for (int i = n - 1; i >= 0; --i) {
    mininto(dp[i][0], dp[i][1]);
    if (i > 0) {
      for (int j = 0; j < 2; ++j) {
        mergeinto(dp[i][j], dp[par[i]][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (dp[0][1][i] <= b) ans = i;
  }
  cout << ans << "\n";
}