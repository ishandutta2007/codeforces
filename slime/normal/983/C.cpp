#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 2005
#define maxs 10000
#define ld double
#define ll long long
#define mod 998244353
using namespace std;
int a[maxn], b[maxn];
int dp[maxn][maxs]; 
int main()
{
//	cout<<((ll)1 << (ll)60)<<endl;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	a[0] = 1;
	for(int i = 0; i < maxs; i++)
	{
		dp[n + 1][i] = 0;
		if(!i) continue;
		int ns[4], nn = i;
		for(int k = 0; k < 4; k++)
			ns[k] = nn % 10, nn /= 10;
		int npl = a[n];
		int mns = 9, mxs = 1;
		for(int k = 0; k < 4; k++)
			if(ns[k]) mns = min(mns, ns[k]), mxs = max(mxs, ns[k]);
		if(npl >= mxs) dp[n + 1][i] = npl - mns;
		else if(npl < mns) dp[n + 1][i] = mxs - npl;
		else dp[n + 1][i] = min(npl - mns, mxs - npl) + mxs - mns;
	}
	for(int i = n; i >= 1; i--)
		for(int j = 0; j < maxs; j++)
		{
			int ns[4], nn = j;
			for(int k = 0; k < 4; k++)
				ns[k] = nn % 10, nn /= 10;
			dp[i][j] = maxn * 1000;
			bool flag = 0;
			for(int k = 0; k < 3; k++)
				if(ns[k] > ns[k + 1]) flag = 1;
			if(flag) continue;
			for(int ed = 1; ed <= 9; ed++)
			{
				int nns[4];
				for(int k = 0; k < 4; k++)
				{
					nns[k] = ns[k];
					if((nns[k] - ed) * (nns[k] - a[i]) <= 0 || (nns[k] - a[i]) * (nns[k] - a[i - 1]) <= 0)
						nns[k] = 0;
				}
				sort(nns, nns + 4);
				if(nns[0] != 0) continue;
				nns[0] = b[i];
				sort(nns, nns + 4);
				
				int nnum = 0;
				for(int k = 3; k >= 0; k--)
					nnum = nnum * 10 + nns[k];
				dp[i][j] = min(dp[i][j], dp[i + 1][nnum] + abs(ed - a[i - 1]) + abs(ed - a[i]));
			}
		}
	printf("%d\n", dp[1][0] + 2 * n);
	return 0;
}