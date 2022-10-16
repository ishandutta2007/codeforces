#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
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
vector<int> G[100001];
vector<pair<int,int>> ed;
int t,n,top,cnt,tot,id[100001],dfn[100001],low[100001],stk[100001],vis[100001],out[100001];
array<int,2> a[100001];
void minn(int &x,int y)
{
	if(x>y)
		x=y;
}
void tarjan(int p)
{
	dfn[p]=low[p]=++cnt;
	stk[++top]=p;
	vis[p]=1;
	for(int i:G[p])
		if(!dfn[i])
		{
			tarjan(i);
			minn(low[p],low[i]);
		}
		elif(vis[i])
			minn(low[p],dfn[i]);
	if(dfn[p]==low[p])
	{
		++tot;
		int k;
		do{
			k=stk[top--];
			id[k]=tot;
			vis[k]=0;
		}while(k!=p);
	}
}
void solve()
{
	n=read();
	top=cnt=tot=0;
	fill(dfn+1,dfn+1+n,0);
	fill(low+1,low+1+n,0);
	fill(vis+1,vis+1+n,0);
	fill(out+1,out+1+n,0);
	for(int i=1;i<=n;i++)
		G[i].clear(); 
	for(int i=1;i<=n;i++)
		a[i]={read(),i};
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		G[a[i][1]].push_back(a[i+1][1]);
	for(int i=1;i<=n;i++)
		a[i]={read(),i};
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		G[a[i][1]].push_back(a[i+1][1]);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	ed.clear();
	for(int i=1;i<=n;++i)
		for(int j:G[i])
			if(id[i]!=id[j])
				ed.push_back({id[i],id[j]});
	sort(ALL(ed));
	ed.erase(unique(ALL(ed)),ed.end());
	for(auto i:ed)
		++out[i.first];
	for(int i=1;i<=n;++i)
		printf("%d",!out[id[i]]);
	putchar('\n');
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}