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
#define MAXN 310000
int f[MAXN][4];int n,m;
int ans[MAXN];int q[MAXN*10];int kao[MAXN];int ds[MAXN];bool inq[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,m)
	{
		int a,b;scanf("%d%d",&a,&b);
		f[a][++f[a][0]]=b;
		f[b][++f[b][0]]=a;
	}
	rep(i,1,n){if(f[i][0]>1){q[++q[0]]=i;kao[i]=1;inq[i]=1;}ds[i]=f[i][0];}
	for(int is=1;is<=q[0];is++)
	{
		//rep(i,1,n)printf("%d ",ds[i]);printf("\n");
		int x=q[is];inq[x]=0;
		if(!kao[x])continue;kao[x]=0;
		ans[x]=!ans[x];ds[x]=f[x][0]-ds[x];
		rep(j,1,f[x][0])
		if(ans[f[x][j]]!=ans[x])
		{
			ds[f[x][j]]--;
			if(ds[f[x][j]]==1)kao[f[x][j]]=0;
		}
		else
		{
			ds[f[x][j]]++;
			if(ds[f[x][j]]==2)
			{
				kao[f[x][j]]=1;
				if(!inq[f[x][j]]){inq[f[x][j]]=1;q[++q[0]]=f[x][j];}
			}
		}
	}
	rep(i,1,n)printf("%d",ans[i]);
	return 0;
}