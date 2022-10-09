#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
using namespace std;
#define int int64_t

int INF = 9e18;
char nl = '\n';
vector<int> r_dir = {-1, 0, 1, 0};
vector<int> c_dir = {0, 1, 0, -1};
const int MOD = 998244353;

int get_num_components_added(int mask, int nmask) {
  int diff_count = __builtin_popcount(mask ^ nmask);
  if (mask == 0 || mask == 3) {
    if (diff_count == 0) { return 0; }
    else { return 1; }
  } else {
    if (diff_count == 2) { return 2; }
    else { return 0; }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(4)));

  for (int i = 0; i < 4; i++) {
    int comp = i == 0 || i == 3 ? 1 : 2;
    if (comp <= k) {
        dp[0][comp][i] = 1;
    }
  }

  // debug(dp);

  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int mask = 0; mask < 4; mask++) {
        for (int nmask = 0; nmask < 4; nmask++) {
          int num_components_added = get_num_components_added(mask, nmask);

          if (j + num_components_added <= k) {
            (dp[i + 1][j + num_components_added][nmask] += dp[i][j][mask]) %= MOD;
          }
        }
      }
    }
  }

  //debug(dp);

  int ans = 0;
  for (int mask = 0; mask < 4; mask++) {
    (ans += dp[n - 1][k][mask]) %= MOD;
  }

  cout << ans << nl;
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  return 0;
}