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
// CURRENT STREAK (easy level): 2 AC in a row

const int MAXN = 2222;
ll chs[MAXN][MAXN];
const int MOD = 998244353;
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  // (n - 1 choose k) * m * (m - 1) ^ k
  chs[0][0] = 1;
  for (int i = 0; i + 1 < MAXN; ++i) {
    for (int j = 0; j <= i; ++j) {
      chs[i + 1][j] += chs[i][j];
      chs[i + 1][j + 1] += chs[i][j];
      chs[i + 1][j] %= MOD;
      chs[i + 1][j + 1] %= MOD;
    }
  }

  ll ans = chs[n - 1][k];
  ans *= m;
  ans %= MOD;
  for (int i = 0; i < k; ++i) {
    ans *= m - 1;
    ans %= MOD;
  }

  cout << ans << "\n";
}