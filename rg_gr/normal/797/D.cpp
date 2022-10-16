#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <map>
#include <stdlib.h>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
int ls[100005],rs[100005],qwq[100005],a[100005];
std::map<int,int> m;
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
void dfs(int u,int minn,int maxn)
{
	if(u==-1)return;
	if(minn<a[u]&&a[u]<maxn)m[a[u]]=1;
	dfs(rs[u],max(minn,a[u]),maxn);
	dfs(ls[u],minn,min(maxn,a[u]));
}
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),ls[i]=read(),rs[i]=read();
		if(ls[i]>0)qwq[ls[i]]=1;
		if(rs[i]>0)qwq[rs[i]]=1;
	}
	int root=0;
	for(int i=1;i<=n;i++)
	{
		if(qwq[i]==0)
		{
			root=i;
			break;
		}
	}
	dfs(root,-0x3f3f3f3f,0x3f3f3f3f);
	int ans=0;
	for(int i=1;i<=n;i++)if(m[a[i]]==0)ans++;
	printf("%d\n",ans);
}
//1m1m4m5m1m4m 1p9p1p9p8p1p 5z