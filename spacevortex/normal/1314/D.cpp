#include<bits/stdc++.h>
#define cmin(a,b) a=min(a,b)
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=90,inf=(ll)1e15;
ll n,K,A,ans=inf;
ll dp[15][N],p[N],col[N];
ll t[N][N];
int main()
{
	srand(time(0));
	ll i,j,k,c;
	n=rd();K=rd();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			t[i][j]=rd();
		}
	}
	for(i=1;i<=n;i++) p[i]=i;
	while((double)clock()/CLOCKS_PER_SEC<2.8)
	{
		random_shuffle(p+2,p+n+1);
		memset(col,0,sizeof(col));
		A=rand()%n+1;
		for(i=A+1;i<=n;i++) col[p[i]]=1;
		memset(dp,0x3f,sizeof(dp));
		dp[0][1]=0;
		for(i=0,c=0;i<K;i++,c^=1)
		{
			for(j=1;j<=n;j++)
			{
				if(col[j]!=c) continue;
				for(k=1;k<=n;k++)
				{
					if(col[k]!=(c^1)) continue;
					cmin(dp[i+1][k],dp[i][j]+t[j][k]);
				}
			}
		}
		ans=min(ans,dp[K][1]);
	}
	printf("%lld\n",ans);
	return 0;
}