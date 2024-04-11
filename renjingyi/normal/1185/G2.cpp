#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const long long mod = 1e9 + 7;
int t[maxn], g[maxn];
long long cnt1[maxn][maxn * maxn];
long long cnt2[maxn][maxn][maxn * maxn];
long long dp[maxn][maxn][maxn][4];
long long fac[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, T;
	cin >> n >> T;
	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	for(int i = 1; i <= n; i ++)
		cin >> t[i] >> g[i];
	cnt1[0][0] = 1;
	for(int i = 1; i <= n; i ++)
		if(g[i] == 1)
			for(int a = n - 1; a >= 0; a --)
				for(int b = T - t[i]; b >= 0; b --)
					if(cnt1[a][b])
						(cnt1[a + 1][b + t[i]] += cnt1[a][b]) %= mod;
	cnt2[0][0][0] = 1;
	for(int i = 1; i <= n; i ++)
		if(g[i] > 1)
			for(int a = n - 1; a >= 0; a --)
				for(int b = n - 1; b >= 0; b --)
					for(int c = T - t[i]; c >= 0; c --)
						if(cnt2[a][b][c])
						{
							if(g[i] == 2)
								(cnt2[a + 1][b][c + t[i]] += cnt2[a][b][c]) %= mod;
							else if(g[i] == 3)
								(cnt2[a][b + 1][c + t[i]] += cnt2[a][b][c]) %= mod;
						}
	dp[0][0][0][0] = 1;
	for(int a = 0; a < n; a ++)
		for(int b = 0; b < n - a; b ++)
			for(int c = 0; c < n - a - b; c ++)
				for(int d = 0; d <= 3; d ++)
					if(dp[a][b][c][d])
					{
						long long now = dp[a][b][c][d];
						if(d == 0)
						{
							(dp[a + 1][b][c][1] += now) %= mod;
							(dp[a][b + 1][c][2] += now) %= mod;
							(dp[a][b][c + 1][3] += now) %= mod;
						}
						else if(d == 1)
						{
							(dp[a][b + 1][c][2] += now) %= mod;
							(dp[a][b][c + 1][3] += now) %= mod;
						}
						else if(d == 2)
						{
							(dp[a + 1][b][c][1] += now) %= mod;
							(dp[a][b][c + 1][3] += now) %= mod;
						}
						else if(d == 3)
						{
							(dp[a + 1][b][c][1] += now) %= mod;
							(dp[a][b + 1][c][2] += now) %= mod;
						}
					}
	long long ans = 0;
	for(int a = 0; a <= n; a ++)
		for(int b = 0; b <= n; b ++)
			for(int c = 0; c <= n; c ++)
			{
				long long tot = 0;
				for(int d = 0; d <= 3; d ++)
					(tot += dp[a][b][c][d]) %= mod;
				if(tot)
				{
					(tot *= fac[a] * fac[b] % mod * fac[c] % mod) %= mod;
					for(int i = 0; i <= T; i ++)
						if(cnt1[a][i] && cnt2[b][c][T - i])
							(ans += tot * cnt1[a][i] % mod * cnt2[b][c][T - i]) %= mod;
				}
			}
	cout << ans << endl;
	
	return 0;
}