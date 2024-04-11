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
const int N=(1<<21)+50;
int n,sx,tot,num,top=0;
int a[N],b[N],ds[N],vis[N],stk[N];
set<int> st[N];
bool QAS=0;
vector<int> e[N];
void eadd(int u,int v)
{
	ds[u]++;ds[v]++;
	e[u].pb(v);e[v].pb(u);
}
void dfs(int x)
{
	vis[x]=1;
	if(x<=2*n) num++;
	for(int v:e[x])
	{
		if(vis[v]) continue;
		dfs(v);
	}
}
void srh(int x)
{
	//printf("srh %d\n",x);
	int v;
	while(!st[x].empty())
	{
		v=*st[x].begin();
		st[x].erase(v);st[v].erase(x);
		srh(v);
	}
	if(x<=2*n) stk[++top]=x;
}
bool check(int ws)
{
	//printf("check %d\n",ws);
	int i;
	sx=(1<<ws)-1;
	memset(ds,0,sizeof(ds));
	memset(vis,0,sizeof(vis));
	tot=2*n+1+sx;
	for(i=1;i<=tot;i++) e[i].clear();
	for(i=1;i<=n;i++)
	{
		eadd(2*i-1,2*i);
		eadd((a[i]&sx)+2*n+1,2*i-1);
		eadd((b[i]&sx)+2*n+1,2*i);
	}
	//for(i=1;i<=tot;i++) printf("#%d %d\n",i,ds[i]);
	for(i=1;i<=tot;i++) if(ds[i]&1) return 0;
	
	num=0;
	dfs(1);
	//printf("num %d\n",num);
	if(num!=(2*n)) return 0;
	if(QAS==0) return 1;
	for(i=1;i<=tot;i++)
	{
		for(int v:e[i])
		{
			st[i].insert(v);
		}
	}
	st[1].erase(2);st[2].erase(1);
	srh(1);
	return 1;
}
int main()
{
	int i,sl,sr,mid,m;
	n=rd();
	for(i=1;i<=n;i++) 
	{
		a[i]=rd();b[i]=rd();
	}
	sl=0;sr=20;//------------------------------------------------------------
	while(sl<sr)
	{
		mid=(sl+sr+1)>>1;
		if(check(mid)==1) sl=mid;
		else sr=mid-1;
	}
	if(sl==0)
	{
		printf("0\n");
		for(i=1;i<=(n*2);i++) printf("%d ",i);
		return 0;
	}
	QAS=1;
	check(sl);
	m=2*n;
	printf("%d\n",sl);
	if(stk[1]==2) m--,printf("1 ");
	for(i=1;i<=m;i++) printf("%d ",stk[i]);
	return 0;
}