#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1000005;
bool vis[N<<1];
char s[N],st[N];
int n,m,L,ans,x,tot,nw,lst,p[N],f[N<<1],len[N<<1],g[N<<1],rk[N<<1],bin[N],trf[N<<1][27];

void add(int c)
{
	int u=lst,v,x=++tot;
	lst=tot,len[x]=len[u]+1;
	for(; u && !(v=trf[u][c]); trf[u][c]=x,u=f[u]);
	if(!u) f[x]=1;
	else if(len[u]+1==len[v]) f[x]=v;
	else
	{
		int w=++tot;
		len[w]=len[u]+1,f[w]=f[v],memcpy(trf[w],trf[v],sizeof(trf[v]));
		for(f[v]=f[x]=w; u && trf[u][c]==v; trf[u][c]=w,u=f[u]);
	}
}

void solve()
{
	ans=0,L=strlen(st+1),x=1,nw=0;
	rep(i,1,L)
	{
		while(x && !trf[x][st[i]-'a']) nw=len[x=f[x]];
		if(!x) x=1,nw=0;
		else x=trf[x][st[i]-'a'],++nw;
	}
	if(nw>=L && !vis[p[0]=x])
		ans=g[x]*(nw>=L);
	vis[p[0]=x]=1;
	rep(i,1,L-1)
	{
		while(x && !trf[x][st[i]-'a']) nw=len[x=f[x]];
		if(!x) x=1,nw=0;
		else x=trf[x][st[i]-'a'],++nw;
		while(x && len[f[x]]>=L) x=f[x];
		if(nw=min(nw,L),nw>=L && !vis[p[i]=x])
			ans=ans+g[x],vis[x]=1;
	}
	rep(i,0,L-1) vis[p[i]]=0;
}

int main()
{
	scanf("%s",s+1),n=strlen(s+1),tot=lst=1;
	rep(i,1,n)
		add(s[i]-'a'),p[i]=lst;
	rep(i,1,n) g[p[i]]=1;
	rep(i,1,tot) ++bin[len[i]];
	rep(i,1,n) bin[i]+=bin[i-1];
	rep(i,1,tot) rk[bin[len[i]]--]=i;
	repd(i,tot,1) g[f[rk[i]]]+=g[rk[i]];
	scanf("%d",&m);
	while(m--)
		scanf("%s",st+1),solve(),printf("%d\n",ans);
	return 0;
}