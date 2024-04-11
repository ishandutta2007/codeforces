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
int n,m,q,top,stk[300001],fa[300001],d[300001];
vector<int> G[300001],ans[300001];
bool dfs(int x,int fa,int tar)
{
	stk[++top]=x;
	if(x==tar)
		return 1;
	for(int i:G[x])
		if(i!=fa)
			if(dfs(i,x,tar))
				return 1;
	top--;
	return 0;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	while(m--)
	{
		int x=read(),y=read();
		if(find(x)!=find(y))
		{
			fa[find(x)]=find(y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		top=0;
		dfs(x,0,y);
		for(int l=1;l<=top;l++)
			ans[i].push_back(stk[l]);
		d[x]^=1;
		d[y]^=1;
	}
	int res=0;
	for(int i=1;i<=n;i++)
		res+=d[i];
	if(res)
	{
		puts("No");
		cout<<res/2;
		return 0;
	}
		puts("Yes");
		for(int i=1;i<=q;i++)
		{
			cout<<ans[i].size()<<endl;
			for(int l:ans[i])
				cout<<l<<" ";
			cout<<endl;
		}
	return 0;
}