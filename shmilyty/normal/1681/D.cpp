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
int getlen(int x)
{
	int res=0;
	while(x)
	{
		res++;
		x/=10;
	}
	return res;
}
int n,x,ans,tot;
map<int,int> vis;
int dfs(int x)
{
	if(getlen(x)==n)
		return vis[x]=0;
	if(vis.count(x))
		return vis[x];
	int &res=vis[x];
	res=INF;
	int ok[10];
	fill(ok,ok+10,0);
	int y=x;
	while(y)
	{
		ok[y%10]=1;
		y/=10;
	}
	for(int i=9;i>=2;i--)
		if(ok[i])
			res=min(res,1+dfs(i*x));
	return res;
}
signed main()
{
	n=read();
	x=read();
	ans=dfs(x);
	if(ans==INF)
		puts("-1");
	else
		cout<<ans;
	return 0;
}