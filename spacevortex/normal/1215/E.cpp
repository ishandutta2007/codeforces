#include<bits/stdc++.h>
#define cmin(a,b) a=min(a,b)
using namespace std;
typedef long long ll;
const ll N=4e5+50,V=(1<<20)+20,P=25;
ll n,tot,sx;
ll a[N],h[P][P],f[P],dp[V];
int main()
{
	ll i,j,k,num,ns,val;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++) scanf("%I64d",&a[i]),a[i]--;
	tot=20;sx=(1<<tot);
	for(i=0;i<tot;i++)
	{
		num=0;
		for(j=1;j<=n;j++)
		{
			if(a[j]==i)
			{
				num++;f[i]+=j-num;
			}
		}
	}
	for(i=0;i<tot;i++)
	{
		for(j=0;j<tot;j++)
		{
			if(i==j) continue;
			num=0;
			for(k=n;k>=1;k--)
			{
				if(a[k]==j) num++;
				if(a[k]==i) h[i][j]+=num;
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(ns=0;ns<sx;ns++)
	{
		for(i=0;i<tot;i++)
		{
			if(ns&(1<<i)) continue;
			val=f[i];
			for(j=0;j<tot;j++)
			{
				if(ns&(1<<j)) val-=h[j][i];
			}
			cmin(dp[ns|(1<<i)],dp[ns]+val);
		}
	}
	printf("%I64d",dp[sx-1]);
	return 0;
}