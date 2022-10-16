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
int n,ans,top,stk[500001],f[500001];
vector<int> G[500001];
void dfs(int x,int fa,int d)
{
	if(G[x].size()==1)
		stk[++top]=d;
	for(int i:G[x])
		if(i!=fa)
			dfs(i,x,d+1);
}
int solve(int x)
{
	top=0;
	dfs(x,1,0);
	sort(stk+1,stk+1+top);
	for(int i=2;i<=top;i++)
		stk[i]=max(stk[i],stk[i-1]+1);
	return stk[top];
}
signed main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i:G[1])
		ans=max(ans,solve(i));
	cout<<ans+1;
	return 0;
}