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
int n,m,f[151][151][80],a[151];
char c[151];
int dfs(int l,int r,int x)
{
	if(l>r)
		return x?-INF:0;
	if(~f[l][r][x])
		return f[l][r][x];
	int &res=f[l][r][x];
	if(x==79)
	{
		res=max(0ll,dfs(l,r,0));
		for(int i=l;i<r;i++)
			res=max(res,dfs(l,i,x)+dfs(i+1,r,x));
	}
	else
	{
		res=-INF;
		if(c[l]==c[r])
			res=max(dfs(l+1,r-1,x+1),dfs(l+1,r-1,0)+a[x*2+2-(l==r)]);
		for(int i=l;i<r;i++)
			res=max({res,dfs(l,i,x)+dfs(i+1,r,0),dfs(l,i,0)+dfs(i+1,r,x)});
	}
	return res;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]<0)
			a[i]=-INF;
	}
	memset(f,-1,sizeof(f));
	scanf("%s",c);
	cout<<dfs(0,n-1,79);
	return 0;
}