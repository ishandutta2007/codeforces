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
const int INF=1e9;
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
int n,ans,f[200001][3];
//012 
vector<int> G[200001];
void dfs(int x,int fa,int d=0)
{
	f[x][1]=INF;
	f[x][0]=1;
	for(int i:G[x])
		if(i!=fa)
		{
			dfs(i,x,d+1);
			f[x][1]=min(f[x][1]+min(f[i][0],f[i][1]),f[x][2]+f[i][0]);
			f[x][2]+=f[i][1];
			f[x][0]+=min(f[i][0],min(f[i][1],f[i][2]));
		}
	if(d<=2)
		f[x][1]=min(f[x][1],f[x][2]);
//	cout<<x<<endl;
//	cout<<f[x][0]<<" "<<f[x][1]<<" "<<f[x][2]<<endl;
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
	dfs(1,0);
	cout<<f[1][1];
	return 0;
}