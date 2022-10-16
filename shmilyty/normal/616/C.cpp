#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int n,m,sz,col,mp[1001][1001];
int px[]={1,0,-1,0};
int py[]={0,1,0,-1};
pair<int,int> vis[1001][1001];
map<int,int> ans;
bool check(int x,int y)
{
	return (x&&x<=n&&y&&y<=m);
}
void dfs(int x,int y,int c,int s)
{
	if(!vis[x][y].first)
	{
		mp[x][y]=1;
		sz++;
		vis[x][y].first=c;
	}
	vis[x][y].second=max(vis[x][y].second,s);
	for(int i=0;i<4;i++)
	{
		int xx=x+px[i],yy=y+py[i];
		if(!check(xx,yy))
			continue;
		if(c&&!mp[xx][yy])
			dfs(xx,yy,c,s);
		if(s&&vis[xx][yy].first==vis[x][y].first&&!vis[xx][yy].second)
			dfs(xx,yy,c,s);
	}
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<m;l++)
			if(s[l]=='*')
				mp[i][l+1]=1;
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			if(!mp[i][l])
			{
				sz=0;
				dfs(i,l,++col,0);
				dfs(i,l,0,sz);
			}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
			if(vis[i][l].first)
				cout<<".";
			else
			{
				ans.clear();
				int an=0;
				for(int j=0;j<4;j++)
					if(check(i+px[j],l+py[j]))
						ans[vis[i+px[j]][l+py[j]].first]=vis[i+px[j]][l+py[j]].second;
				for(auto j:ans)
					an+=j.second;
				cout<<(an+1)%10;
			}
		cout<<endl;
	}
	return 0;
}