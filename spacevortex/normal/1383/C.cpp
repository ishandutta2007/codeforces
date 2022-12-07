#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
using namespace std;
const int N=2e5+50,P=30,V=(1<<20)+20;
int n,m=20,ans,num,sx;
char s[N];
int a[N],b[N];
int e[P][P],t[P][P],vis[P],pl[P],f[P];
int dp[V];
void dfs(int x)
{
	int i;
	vis[x]=1;
	pl[num++]=x;
	for(i=1;i<=m;i++)
	{
		if(e[x][i]&&vis[i]==0) dfs(i);
	}
}
int check()
{
	int ns,i,j,vs;
	for(i=0;i<num;i++)
	{
		f[i]=0;
		for(j=0;j<num;j++) if(t[pl[i]][pl[j]]) f[i]|=(1<<j);
	}
	sx=1<<num;
	for(i=0;i<sx;i++) dp[i]=0;
	for(ns=0;ns<sx;ns++)
	{
		vs=(sx-1)^ns;
		for(i=0;i<num;i++)
		{
			if(ns&(1<<i)) continue;
			if((vs&f[i])==f[i]) cmax(dp[ns|(1<<i)],dp[ns]+1);
			else cmax(dp[ns|(1<<i)],dp[ns]);
		}
	}
	return num-1+(num-dp[sx-1]);
}
void Solve()
{
	int i;
	scanf("%d",&n);
	scanf("%s",s+1);for(i=1;i<=n;i++) a[i]=s[i]-'a'+1;
	scanf("%s",s+1);for(i=1;i<=n;i++) b[i]=s[i]-'a'+1;
	memset(vis,0,sizeof(vis));
	memset(e,0,sizeof(e));
	memset(t,0,sizeof(t));
	for(i=1;i<=n;i++)
	{
		if(a[i]==b[i]) continue;
		t[a[i]][b[i]]=1;
		e[a[i]][b[i]]=e[b[i]][a[i]]=1;
	}
	ans=0;
	for(i=1;i<=m;i++)
	{
		if(vis[i]) continue;
		num=0;
		dfs(i);
		ans+=check();
	}
	printf("%d\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) Solve();
	return 0;
}