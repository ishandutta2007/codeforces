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
const int N=1e6+50;
int n,m;
vector<int> e[N];
int t[N],p[N],col[N],vis[N];
bool cmp(const int &a,const int &b){return t[a]<t[b];}
int main()
{
	int i,u,v,x;
	n=rd();m=rd();
	for(i=1;i<=m;i++)
	{
		u=rd();v=rd();
		e[u].pb(v);e[v].pb(u);
	}
	for(i=1;i<=n;i++)
	{
		t[i]=rd();p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		x=p[i];
		for(int v:e[x])
		{
			vis[col[v]]=i;
		}
		col[x]=1;
		while(vis[col[x]]==i) col[x]++;
		if(col[x]!=t[x])
		{
			puts("-1");
			return 0;
		}
	}
	for(i=1;i<=n;i++) printf("%d ",p[i]);
	return 0;
}