#include<bits/stdc++.h>
#define pb push_back
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
int mrd(){return rand()&((1<<15)-1);}
int srd(){return mrd()+(mrd()<<15);}
const int N=2e5+50,inf=1e9+5;
int n,m,rt,tim,num;
int vis[N],tag[N],val[N],id[N],ans[N],det[N];
vector<int> e[N];
bool dfs(int x)
{
	vis[x]=tag[x]=tim;
	for(int v:e[x])
	{
		if(vis[v]==tim)
		{
			if(tag[v]!=tim) return 0;
		}
		else 
		{
			if(dfs(v)==0) return 0;
		}
	}
	tag[x]=0;
	return 1;
}
bool query()
{
	//printf("query %d\n",rt);
	rt=srd()%n+1;
	tim++;
	return dfs(rt);
}
void srh(int x)
{
	vis[x]=tim;
	for(int v:e[x])
	{
		if(vis[v]==tim)
		{
			val[x]++;val[v]--;
			if(det[v]<det[id[x]]) id[x]=v;
		}
		else
		{
			det[v]=det[x]+1;
			srh(v);
			if(det[id[v]]<det[id[x]]) id[x]=id[v];
			val[x]+=val[v];
		}
	}
}
void srh2(int x)
{
	vis[x]=tim;
	if(val[x]>=2||ans[id[x]]==1) ans[x]=1;
	for(int v:e[x])
	{
		if(vis[v]!=tim) srh2(v);
	}
}
void Solve()
{
	int i,u,v;
	int tes=120;
	n=rd();m=rd();
	for(i=1;i<=n;i++) e[i].clear();
	for(i=1;i<=m;i++)
	{
		u=rd();v=rd();
		e[u].pb(v);
	}
	rt=-1;
	while(tes>0)
	{
		tes--;
		if(query()==1) break;
	}
	if(tes==0)
	{
		puts("-1");
		return ;
	}
	//printf("rt %d\n",rt);
	tim++;
	for(i=1;i<=n;i++) val[i]=0,ans[i]=0,id[i]=0;
	det[rt]=1;
	det[0]=inf;
	srh(rt);

	tim++;
	srh2(rt);
	num=0;
	for(i=1;i<=n;i++) if(ans[i]==0) num++;
	if(num*5<n) puts("-1");
	else
	{
		for(i=1;i<=n;i++) if(ans[i]==0) printf("%d ",i);
		putchar('\n');
	}
}
int main()
{
	int T;
	T=rd();
	while(T--) Solve();
}