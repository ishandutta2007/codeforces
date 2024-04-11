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
int t,n,fa[101],dis[101][101],ok[101][101][101];
queue<int> q;
vector<int> G[101];
void dfs(int x,int fa,int rt)
{
	for(int i:G[x])
		if(i!=fa)
		{
			dis[i][rt]=dis[x][rt]+1;
			dfs(i,x,rt);
		}
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
		G[i].clear();
	memset(fa,0,sizeof(fa));
	for(int i=1;i<=n;i++)
		if(ok[x][i][1])
		{
			fa[i]=1;
			q.push(i);
		}
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		for(int i=2;i<=n;i++)
		{
			if(fa[i])
				continue;
				// return 0;
			if(ok[i][fa[f]][f]&&i!=fa[f])
			{
				fa[i]=f;
				q.push(i);
			}
		}
	}
	for(int i=2;i<=n;i++)
		if(!fa[i])
			return 0;
	for(int i=2;i<=n;i++)
	{
		G[i].push_back(fa[i]);
		G[fa[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
		dfs(i,0,i);
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			for(int j=1;j<=n;j++)
				if((dis[i][j]==dis[j][l])!=ok[i][l][j])
					return 0;
	return 1;
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			ok[i][i][l]=1;
	for(int i=1;i<n;i++)
		for(int l=1;l<=n-i;l++)
		{
			string s;
			cin>>s;
			for(int j=1;j<=n;j++)
				ok[i][i+l][j]=ok[i+l][i][j]=s[j-1]-'0';
		}
	for(int i=2;i<=n;i++)
		if(check(i))
		{
			puts("Yes");
			for(int i=2;i<=n;i++)
				cout<<fa[i]<<" "<<i<<endl;
			return ;
		}
	puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}