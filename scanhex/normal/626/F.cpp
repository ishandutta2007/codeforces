#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int mod=1e9+7;

const int N=202, K=1010, M=505;
int dp[N][N][K];

void ad(int& a, int b) {
	 if ((a += b) >= mod) a -= mod;
}
int mu(int a, int b) {
	return (nagai) a * b % mod;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int>a(n);
  for(auto&x:a)cin >> x;
  sort(a.begin(),a.end());
  dp[0][0][0] = 1;
  for(int i = 0; i <= n; ++i) {
	  int delta = i == 0 ? a[i] : a[i] - a[i - 1];
	  for(int j = 0; j <= i; ++j) {
		  for(int l = 0; l <= k; ++l) {
//			  if (dp[i][j][l])
//				  cerr << i << ' ' << j << ' ' << l << ' ' << dp[i][j][l] << '\n';
			  if (i == n) continue;
			  int ll = l + delta * j;
			  if (ll <= k)
				  ad(dp[i + 1][j][ll], mu(j + 1, dp[i][j][l]));
			  if (ll <= k && j > 0) 
				  ad(dp[i + 1][j - 1][ll], mu(j, dp[i][j][l]));
			  if (ll <= k)
				  ad(dp[i + 1][j + 1][ll], dp[i][j][l]);
		  }
	  }
  }
  int s = 0;
  for(int i = 0; i <= k; ++i) 
	  ad(s, dp[n][0][i]);
  cout << s << '\n';
  return 0;
}