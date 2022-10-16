#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int t,n,ok,a[200001];
std::vector<int> G[200001];
void dfs(int x,int fa)
{
	if(fa&&G[x].size()==1)
	{
		a[x]=1;
		return ;
	}
	a[x]=(G[x].size()+1)/2;
	for(int i:G[x])
		if(i!=fa)
		{
			dfs(i,x);
			a[x]-=a[i];
		}
	if(a[x]<0||a[x]>1)
		ok=0;
}
void dfs1(int x,int fa)
{
	// cout<<x<<" "<<fa<<endl;
	vector<int> v[2];
	for(int i:G[x])
		if(i!=fa)
			v[a[i]].push_back(i);
		else
			v[a[x]].push_back(x);
	// cout<<v[0].size()<<"-"<<v[1].size()<<endl;
	if(v[1].size()==v[0].size())
		swap(v[1],v[0]);
	for(int i=0;i<v[1].size();i++)
	{
		if(v[1][i]==x)
			cout<<x<<" "<<fa<<'\n';
		else
			dfs1(v[1][i],x);
		if(v[0].size()!=i)
		{
			if(v[0][i]==x)
				cout<<x<<" "<<fa<<'\n';
			else
				dfs1(v[0][i],x);
		}
	}
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	ok=1;
	dfs(1,0);
	if((!ok)||a[1])
	{
		puts("NO");
		return ;
	}
	puts("YES");
	dfs1(1,0);
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}