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
int n,f[200001][2],vis[200001][2],a[200001];
int dfs(int x,int y)
{
	if(x<1||x>n)
		return 0;
	int &res=f[x][y],&c=vis[x][y],k;
	if(x==1||c==a[1])
		return res=-1;
	if(!c)
	{
		c=a[1];
		if(y)
			k=dfs(x-a[x],0);
		else
			k=dfs(x+a[x],1);
		if(k<0)
			res=-1;
		else
			res=k+a[x];
	}
	return res;
}
signed main()
{
	n=read();
	for(int i=2;i<=n;i++)
		a[i]=read();
	for(a[1]=1;a[1]<n;a[1]++)
	{
		int k=dfs(a[1]+1,1);
		if(k<0)
			puts("-1");
		else
			cout<<k+a[1]<<endl;
	}
	return 0;
}