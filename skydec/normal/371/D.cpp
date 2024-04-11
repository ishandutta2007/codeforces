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
int n;int res[210000];int m;int fa[210000];int yb[210000];
int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
int main()
{
	scanf("%d",&n);rep(i,1,n){scanf("%d",&res[i]);fa[i]=i;yb[i]=res[i];}
	fa[n+1]=n+1;
	scanf("%d",&m);
	while(m--)
	{
		int opt;scanf("%d",&opt);
		if(opt==2)
		{
			int k;scanf("%d",&k);
			printf("%d\n",yb[k]-res[k]);
		}
		else
		{
			int x,k;scanf("%d%d",&k,&x);
			int now=get(k);
			while(x)
			{
				if(now==n+1)break;
				int u=min(x,res[now]);
				//printf("_%d %d %d\n",now,res[now],u);
				res[now]-=u;
				x-=u;
				if(!res[now]){fa[now]=now+1;}
				now=get(now);
			}
		}
	}
}