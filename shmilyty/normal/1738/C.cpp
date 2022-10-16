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
int t,n,ok[101][101][2];
int dfs(int x,int y,int op)
{
	if(~ok[x][y][op])
		return ok[x][y][op];
	if(x+y==1)
	{
		if(y)
			return op;
		return op^1;
	}
	int &res=ok[x][y][op];
	res=0;
	if(!op)
	{
		if(y&1)
		{
			res=!dfs(x,y-1,0);
			if(x)
				res|=!dfs(x-1,y,0);
			return res;
		}	
		if(x)
			res|=!dfs(x-1,y,1);
		if(y)
			res|=!dfs(x,y-1,1);
		return res;
	}
	if(y&1)
	{
		res=!dfs(x,y-1,1);
		if(x)
			res|=!dfs(x-1,y,1);
		return res;
	}	
	if(x)
		res|=!dfs(x-1,y,0);
	if(y)
		res|=!dfs(x,y-1,0);
	return res;
}
void solve()
{
	n=read();
	int num0=0,num1=0;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(x&1)
			num1++;
		else
			num0++;
	}
	if(!dfs(num0,num1,0))
		puts("Bob");
	else
		puts("Alice");
}
signed main()
{
	memset(ok,-1,sizeof(ok));
	t=read();
	while(t--)
		solve();
	return 0;
}