#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
// #define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
// const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,mod,ans[2001],f[2001][2001],s[2001][2001],d[2001][2001],g[2001][2001],C[2001][2001];
std::vector<int> G[2001],pre,suf,son;
void dfs(int x,int fa,int id)
{
	int res2=1;
	for(int i:G[x])
		if(i!=fa)
		{
			dfs(i,x,id);
			res2=1ll*res2*s[i][id]%mod;
		}
	if(x==1)
	{
		f[x][id]=res2;
		s[x][id]=(f[x][id]+s[x][id-1])%mod;
		return ;
	}
	d[x][id]=res2;
	f[x][id]=res2;
	pre.clear();
	son.clear();
	for(int i:G[x])
		if(i!=fa)
		{
			pre.push_back(s[i][id]);
			son.push_back(i);
		}
	suf=pre;
	reverse(ALL(suf));
	for(int i=1;i<pre.size();i++)
		pre[i]=1ll*pre[i-1]*pre[i]%mod;
	for(int i=1;i<suf.size();i++)
		suf[i]=1ll*suf[i-1]*suf[i]%mod;
	reverse(ALL(suf));
	for(int i=0;i<son.size();i++)
	{
		g[son[i]][id]=(g[son[i]][id-1]+1ll*(i?pre[i-1]:1ll)*(i+1<son.size()?suf[i+1]:1ll)%mod)%mod;
		(f[x][id]+=1ll*f[son[i]][id]*g[son[i]][id-1]%mod)%=mod;
	}
	s[x][id]=(f[x][id]+s[x][id-1])%mod;
}
signed main()
{
	n=read();
	mod=read();
	C[0][0]=1;
	for(int i=1;i<=2000;i++)
	{
		C[i][0]=1;
		for(int l=1;l<=i;l++)
			C[i][l]=(C[i-1][l-1]+C[i-1][l])%mod;
	}
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<n;i++)
	{
		dfs(1,0,i);
		ans[i]=f[1][i];
		for(int l=1;l<i;l++)
			(ans[i]+=mod-1ll*C[i][l]*ans[l]%mod)%=mod;
		cout<<ans[i]<<' ';
	}
	return 0;
}