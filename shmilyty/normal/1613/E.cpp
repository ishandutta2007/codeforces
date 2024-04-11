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
int t,n,m,sx,sy;
int tx[]={1,0,-1,0};
int ty[]={0,1,0,-1};
string s[1000001],vis[1000001];
bool ok(int x,int y)
{
	return x>=0&&x<n&&y>=0&&y<m;
}
void bfs()
{
	queue<array<int,2>> q;
	q.push({sx,sy});
	for(int i=0;i<n;i++)
	{
		string ss;
		for(int l=0;l<m;l++)
			ss+="0";
		vis[i]=ss;
	}
	while(!q.empty())
	{
		int x=q.front()[0],y=q.front()[1];
		q.pop();
		if(vis[x][y]=='1')
			continue;
		vis[x][y]='1';
		for(int i=0;i<4;i++)
		{
			int xx=x+tx[i],yy=y+ty[i];
			if(!ok(xx,yy))
				continue;
			if(s[xx][yy]=='#')
				continue;
			if(s[xx][yy]=='+')
			{
				q.push({xx,yy});
				continue;
			}
			int num=0;
			for(int l=0;l<4;l++)
				if(ok(xx+tx[l],y+ty[l])&&s[xx+tx[l]][yy+ty[l]]=='.')
					num++;
			if(num>=2)
				continue;
			if(s[xx][yy]=='.')
				s[xx][yy]='+';
			q.push({xx,yy});
		}
	}
}
void solve()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		for(int l=0;l<m;l++)
			if(s[i][l]=='L')
			{
				sx=i;
				sy=l;
				break;
			}
//	for(int i=0;i<15;i++)
		bfs();
	for(int i=0;i<n;i++)
	{
		cout<<s[i];
		cout<<'\n';
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}