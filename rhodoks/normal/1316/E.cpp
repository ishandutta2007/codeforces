#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 110000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL dp[MAXN][130]; 
int n,p,k;
int a[MAXN];
int s[MAXN][8];
int ord[MAXN];
int cnt[130];
bool cmp(int x,int y)
{
	return a[x]>a[y];
}

int main()
{
	MST(dp,-INF);
	cin>>n>>p>>k;
	for (int i=0;i<(1<<p);i++)
		for (int j=0;j<p;j++)
			if (i & (1<<j))
				cnt[i]++;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ord[i]=i;
	}
	sort(ord+1,ord+1+n,cmp);
	for (int i=1;i<=n;i++)
		for (int j=0;j<p;j++)
			scanf("%d",&s[i][j]);
	dp[0][0]=0;
	for (int i=1;i<=k;i++)
	{
		int pos=ord[i];
		for (int msk=0;msk<(1<<p);msk++)
		{
			dp[i][msk]=max(dp[i][msk],dp[i-1][msk]+a[pos]);
			for (int j=0;j<p;j++)
				if ((msk & (1<<j)) == 0)
					dp[i][msk | (1<<j)]=max(dp[i][msk | (1<<j)],dp[i-1][msk]+s[pos][j]);
			//cout<<dp[i][msk]<<' ';
		}
		//cout<<endl;
	}
	for (int i=k+1;i<=n;i++)
	{
		int pos=ord[i];
		for (int msk=0;msk<(1<<p);msk++)
		{
			if (i-k<=cnt[msk])
				dp[i][msk]=max(dp[i][msk],dp[i-1][msk]+a[pos]);
			else
				dp[i][msk]=max(dp[i][msk],dp[i-1][msk]);
			for (int j=0;j<p;j++)
				if ((msk & (1<<j)) == 0)
					dp[i][msk | (1<<j)]=max(dp[i][msk | (1<<j)],dp[i-1][msk]+s[pos][j]);
		}
	}
	cout<<dp[n][(1<<p)-1];
	return ~~(0^_^0);
}