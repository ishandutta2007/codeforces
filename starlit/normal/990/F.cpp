#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200005
using namespace std;
int n,m,s[N],to[N<<1],hd[N<<1],val[N<<1],lk[N],cnt=1,
sum[N];
bool vis[N];
inline void add(int u,int v)
{to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;}
void dfs(int x)
{
	sum[x]=s[x];vis[x]=1;
	for(int s,i=lk[x];i;i=hd[i])
	if(!vis[s=to[i]])
	dfs(s),sum[x]+=sum[s],
	val[i]=sum[s];
}
int u,v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",s+i);
	scanf("%d",&m);
	for(;m--;)
	{
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1);
	if(sum[1])return puts("Impossible"),0;
	puts("Possible");
	for(int i=2;i<=cnt;i+=2)
	if(val[i^1])printf("%d\n",-val[i^1]);
	else printf("%d\n",val[i]);

}