#include<bits/stdc++.h>
#define cmin(a,b) a=min(a,b)
using namespace std;
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const int N=2050,M=2e4+50;
int n,m,K,cnt=1,tim=0;
int col[M],vis[M],F[N],G[N],s[2];
int he[N],nh[N][2];
struct Edge{int v,id,nxt;}e[M];
void eadd(int u,int v,int i)
{
	cnt++;e[cnt].v=v;e[cnt].id=i;e[cnt].nxt=he[u];he[u]=cnt;
	cnt++;e[cnt].v=u;e[cnt].id=i;e[cnt].nxt=he[v];he[v]=cnt;
}
void query(int u,int *f)
{
	int i;
	for(i=0;i<=K;i++) f[i]=0;
	for(i=he[u];i;i=e[i].nxt)
	{
		f[col[e[i].id]]++;
	}
	f[0]=f[1];
	for(i=2;i<=K;i++) cmin(f[0],f[i]);
}
void dfs(int u,int c)
{
	int v;
	for(int &i=nh[u][c];i;i=e[i].nxt)
	{
		if(vis[e[i].id]==tim) continue;
		if(col[e[i].id]==s[c])
		{
			col[e[i].id]=s[c^1];
			vis[e[i].id]=tim;
			v=e[i].v;
			i=e[i].nxt;
			dfs(v,c^1);
			return ;
		}
	}
}
int main()
{
	int i,j,u,v;
	n=rd();m=rd();K=rd();
	if(K==1)
	{
		while(m--) puts("1");
		return 0;
	}
	for(i=1;i<=n;i++) rd();
	for(i=1;i<=m;i++)
	{
		tim=i;
		u=rd();v=rd();
		//printf("#%d new edge %d %d\n",i,u,v);
		query(u,F);query(v,G);
		//printf("P %d %d\n",F[1],G[1]);
		for(j=1;j<=K;j++)
		{
			if(F[j]<F[0]+2&&G[j]<G[0]+2) 
			{
				col[i]=j;break;
			}
		}
		if(col[i]==0)
		{
			//puts("OK");
			for(s[0]=1;F[s[0]]!=F[0];s[0]++);
			for(s[1]=1;G[s[1]]!=G[0];s[1]++);
			col[i]=s[1];
			for(j=1;j<=n;j++) nh[j][0]=nh[j][1]=he[j];
			dfs(u,1);
		}
		//printf("col %d\n",col[i]);
		eadd(u,v,i);
	}
	for(i=1;i<=m;i++) printf("%d\n",col[i]);
	return 0;
}