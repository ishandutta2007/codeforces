/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e6+100;
int n,fa[N],sz[N],cnt[N];
long long ans,v[N],w[N];
vector <int> e[N];
bool dp[N],f[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void dfs(int x)
{
	sz[x]=1;
	for (int u:e[x]) if (u!=fa[x])
	{
		dfs(u);
		sz[x]+=sz[u];v[x]+=v[u];
	}
	v[x]+=sz[x];
}
void dfs1(int x)
{
	for (int u:e[x]) if (u!=fa[x])
	{
		v[x]-=v[u];
		v[x]-=sz[x];v[u]-=sz[u];
		sz[x]-=sz[u];sz[u]+=sz[x];
		v[x]+=sz[x];v[u]+=sz[u];
		v[u]+=v[x];
		w[u]=v[x];
		dfs1(u);
		v[u]-=v[x];
		v[u]-=sz[u];v[x]-=sz[x];
		sz[u]-=sz[x];sz[x]+=sz[u];
		v[u]+=sz[u];v[x]+=sz[x];
		v[x]+=v[u];
	}
}
void solve(int x,long long all)
{
	memset(cnt,0,sizeof(cnt));
	memset(dp,0,sizeof(dp));
	for (int u:e[x])
	{
		if (u==fa[x]) cnt[n-sz[x]]++;
		else cnt[sz[u]]++;
	}
	int sum=0;dp[0]=1;
	for (int i=1;i<=n;i++) if (cnt[i])
	{
		sum+=i*cnt[i];
		for (int j=0;j<i;j++)
		{
			int ret=0;
			for (int k=j;k<=sum;k+=i)
			{
				f[k]=(ret>0);
				ret+=(dp[k]>0);
				int now=k-cnt[i]*i;
				ret-=(now>=0&&dp[now]);
			}
		}
		for (int j=0;j<=sum;j++) dp[j]|=f[j],f[j]=0;
	}
	for (int i=0;i<=n;i++) if (dp[i])
	{
		int A=i+1,B=n-i;
		ans=max(ans,1ll*A*B+all);
	}
}
signed main()
{
	n=read();
	for (int i=2;i<=n;i++)
	{
		fa[i]=read();
		// printf("%d %d\n",i,fa[i]);
		e[i].push_back(fa[i]);
		e[fa[i]].push_back(i);
	}
	dfs(1);
	dfs1(1);
	for (int i=1;i<=n;i++)
	{
		int MAX=0;long long all=0;
		for (int x:e[i])
		{
			if (x==fa[i]) MAX=max(MAX,n-sz[i]),all+=w[i];
			else MAX=max(MAX,sz[x]),all+=v[x];
		}
		if (MAX>=n/2)
		{
			int A=MAX+1,B=n-MAX;
			ans=max(ans,1ll*A*B+all);
			continue;
		}
		solve(i,all);
	}
	printf("%lld\n",ans);
}