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
int n,m,vis[1001][1001],a[1001][1001];
vector<array<int,3>> v;
queue<array<int,3>> q;
int check(int x,int y)
{
	int maxx=max({a[x][y],a[x+1][y],a[x][y+1],a[x+1][y+1]});
	if(maxx==-1)
		return 0;
	if(a[x][y]>0&&a[x][y]!=maxx)
		return 0;
	if(a[x+1][y]>0&&a[x+1][y]!=maxx)
		return 0;
	if(a[x][y+1]>0&&a[x][y+1]!=maxx)
		return 0;
	if(a[x+1][y+1]>0&&a[x+1][y+1]!=maxx)
		return 0;
	return maxx;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			a[i][l]=read();
	for(int i=1;i<n;i++)
		for(int l=1;l<m;l++)
			if(check(i,l))
			{
				q.push({i,l,a[i][l]});
				vis[i][l]=1;	
			}
	while(!q.empty())
	{
		auto x=q.front();
		q.pop();
		v.push_back(x);
		a[x[0]][x[1]]=-1;
		a[x[0]+1][x[1]]=-1;
		a[x[0]][x[1]+1]=-1;
		a[x[0]+1][x[1]+1]=-1;
		for(int i=max(1ll,x[0]-1);i<=min(n-1,x[0]+1);i++)
			for(int l=max(1ll,x[1]-1);l<=min(m-1,x[1]+1);l++)
				if(check(i,l)&&!vis[i][l])
				{
					q.push({i,l,check(i,l)});
					vis[i][l]=1;
				}
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			if(a[i][l]>0)
			{
				puts("-1");
				return 0;
			}
	reverse(ALL(v));
	cout<<v.size()<<endl; 
	for(auto i:v)
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<'\n';
	return 0;
}