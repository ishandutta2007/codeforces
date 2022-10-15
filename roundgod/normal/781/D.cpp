#include<bits/stdc++.h>
#define MAXN 505
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,m;
bitset<MAXN> f[64][MAXN],g[64][MAXN],p,q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		x--;y--;
		if(t==0) f[0][x][y]=1; else g[0][x][y]=1;
	}
	for(int i=1;i<=62;i++)
	{
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			{
				if(f[i-1][j][k]) f[i][j]|=g[i-1][k];
				if(g[i-1][j][k]) g[i][j]|=f[i-1][k];
			}
	}
	for(int i=0;i<n;i++)
	{
		if(f[61][0][i])
		{
			puts("-1");
			return 0;
		}
	}
	int val=0;
	ll ans=0;
	p[0]=1;
	for(int i=61;i>=0;i--)
	{
		for(int j=0;j<n;j++)
			q[j]=0;
		for(int j=0;j<n;j++)
			if(p[j]) {if(val==0) q|=f[i][j]; else q|=g[i][j];}
		if(q.any())
		{
			val^=1;
			ans+=(1LL<<i);
			p=q;
		}
	}
	if(ans>1000000000000000011) ans=-1;
	printf("%I64d\n",ans);
}