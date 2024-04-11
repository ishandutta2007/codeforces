/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int n,de[N],sum[N][2],ans;
vector <int> e[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void dfs(int x,int fa)
{
	sum[x][de[x]&1]++;
	for (int u:e[x]) if (u!=fa)
	{
		de[u]=de[x]+1;
		dfs(u,x);
		sum[x][0]+=sum[u][0];
		sum[x][1]+=sum[u][1];
	}
}
void dfs1(int x,int fa)
{
	ans=min(ans,sum[x][0]-1);
	for (int u:e[x]) if (u!=fa)
	{
		sum[x][0]-=sum[u][0];sum[x][1]-=sum[u][1];
		swap(sum[x][0],sum[x][1]);swap(sum[u][0],sum[u][1]);
		sum[u][0]+=sum[x][0];sum[u][1]+=sum[x][1];
		dfs1(u,x);
		sum[u][0]-=sum[x][0],sum[u][1]-=sum[x][1];
		swap(sum[x][0],sum[x][1]);swap(sum[u][0],sum[u][1]);
		sum[x][0]+=sum[u][0];sum[x][1]+=sum[u][1];
	}
}
signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	ans=inf;
	dfs(1,1);
	dfs1(1,1);
	printf("%d\n",ans);
}