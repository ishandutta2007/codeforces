#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int N=1000010;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10ll+ch-'0',ch=getchar();
	return x*f;
}
int n,sz[N],rt,v[N];
LL f[N];
vector<int>G[N];
void dfs1(int x,int fa)
{
	v[x]=0;
	sz[x]=1;
	for(int y:G[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		sz[x]+=sz[y];
		v[x]=max(v[x],sz[y]);
	}
	v[x]=max(v[x],n-sz[x]);
	if(!rt||v[x]<v[rt])rt=x;
}
LL ans;
void dfs2(int x,int fa)
{
	sz[x]=1;
	for(int y:G[x])
	{
		if(y==fa)continue;
		dfs2(y,x);
		sz[x]+=sz[y];
		f[x]+=f[y];
	}
	f[x]+=sz[x];
}
int a[N],la,cnt[N];
bitset<N>g;
void dp()
{
//	printf("rt = %d\n",rt);
	ans=f[rt]-sz[rt];
//	printf("ans = %lld\n",ans);
	int m=0;
	for(int y:G[rt])cnt[sz[y]]++;
	for(int i=1;i<=n;i++)
	if(cnt[i])
	{
		for(int j=0;j<=20;j++)
		if(cnt[i]>=(1<<j))
		{
			a[++la]=(1<<j)*i;
			cnt[i]-=(1<<j);
		}
		if(cnt[i])a[++la]=cnt[i]*i;
	}
	///////////////////////////////////////
	g.reset();
//	for(int i=1;i<=la;i++)printf("%d ",a[i]);puts("");
	g[0]=1;
	for(int i=1;i<=la;i++)g|=(g<<a[i]);
	LL t=0;
	for(int i=1;i<=n;i++)
	if(g[i])t=max(t,(LL)(i+1)*(n-i));
	ans+=t;
}
int main()
{
	n=read();
	for(int i=2;i<=n;i++)
	{
		int x=read();
		G[x].emplace_back(i);
		G[i].emplace_back(x);
	}
	dfs1(1,0);
	dfs2(rt,0);
	dp();
	printf("%lld\n",ans);
 	return 0;
}