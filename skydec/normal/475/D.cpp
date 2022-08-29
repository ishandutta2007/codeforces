#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
#define MAXN 250000
int n,q;int a[MAXN];
int g[MAXN][20];int LG[MAXN];
int TW[MAXN];
int GCD(int x,int y)
{
	if(!x||!y)return x+y;
	return GCD(y,x%y);
}
void init()
{
	LG[1]=0;TW[0]=1;rep(j,1,17)TW[j]=TW[j-1]*2;
	rep(j,1,16)
	rep(i,TW[j],TW[j+1]-1)LG[i]=j;
	rep(i,1,n)g[i][0]=a[i];
	rep(j,1,17)
	rep(i,1,n)
	g[i][j]=GCD(g[i][j-1],g[i+TW[j-1]][j-1]);
}
int gcd(int l,int r)
{
	int u=LG[r-l+1];
	return GCD(g[l][u],g[r-TW[u]+1][u]);
}
map<int,LL>hehe;
int main()
{
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	init();
	rep(i,1,n)
	{
		for(int u=i;u<=n;u++)
		{
			int p=gcd(i,u);
			int l=u;int r=n;int res=0;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(gcd(i,mid)==p)
				{
					res=mid;l=mid+1;
				}else r=mid;
			}
			if(gcd(i,l)==p)res=l;
			hehe[p]+=1ll*(res-u+1);
			u=res;
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		int x;scanf("%d",&x);printf("%I64d\n",hehe[x]);
	}
	return 0;
}