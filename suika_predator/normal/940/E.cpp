#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 100005
using namespace std;
int n, c;
int a[maxn];
ll dp[maxn];
int mns[17][maxn];
int lg[maxn];
int q(int l, int r)
{
	int len = (r - l + 1);
	int ns = lg[len];
	int ans = min(mns[ns][l], mns[ns][r - (1 << ns) + 1]);
	return ans;
}
int main()
{
	scanf("%d%d", &n, &c);
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), ans += a[i];
	for(int i = 0; i < 17; i++)
		for(int j = (1 << i); j < maxn; j++)
			lg[j] = i;
	for(int i = 0; i < 17; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j + (1 << i) > n + 1) continue;
			else if(!i) mns[i][j] = a[j];
			else mns[i][j] = min(mns[i - 1][j], mns[i - 1][j + (1 << (i - 1))]);
			// cout<<i<<" "<<j<<" "<<mns[i][j]<<endl;
		}
	}
	dp[n + 1] = 0;
	for(int i = n; i >= 1; i--)
	{
		dp[i] = dp[i + 1];
		if(i + c <= n + 1)
			dp[i] = max(dp[i], dp[i + c] + q(i, i + c - 1));
	}
	ans -= dp[1];
	printf("%lld\n", ans);
	return 0;
}