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
int n,m,k,area,mp[202][202],vis[202][202]; 
int tx[]={0,1,0,-1};
int ty[]={1,0,-1,0};
vector<int> ans;
bool ok(int x,int y)
{
	return (x>0&&y>0&&x<=2*n+1&&y<=2*m+1);
}
void dfs(int x,int y)
{
	vis[x][y]=1;
	area+=mp[x][y];
	for(int i=0;i<4;i++)
	{
		int xx=x+tx[i],yy=y+ty[i];
		if(ok(xx,yy)&&!vis[xx][yy]&&mp[xx][yy]!=2)
			dfs(xx,yy);
	}
}
signed main()
{
	n=read();
	m=read();
	k=read();
	for(int i=2;i<=2*n;i+=2)
		for(int l=2;l<=2*m;l+=2)
			mp[i][l]=1;
	while(k--)
	{
		int x=read(),y=read(),xx=read(),yy=read();
		if(x==xx)
			for(int i=y*2+1;i<=yy*2+1;i++)
				mp[x*2+1][i]=2;
		else
			for(int i=x*2+1;i<=xx*2+1;i++)
				mp[i][y*2+1]=2;
	}
	for(int i=1;i<=2*n+1;i++)
		for(int l=1;l<=2*m+1;l++)
			if(!vis[i][l]&&mp[i][l]!=2)
			{
				area=0;
				dfs(i,l);
				ans.push_back(area);
			}
	sort(ALL(ans));
	for(int i:ans)
		cout<<i<<" ";
	return 0;
}