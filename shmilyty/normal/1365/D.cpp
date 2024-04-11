#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int tx[]={1,0,-1,0};
int ty[]={0,1,0,-1};
int t,n,m,mp[51][51];
vector<pair<int,int> > g,b;
queue<pair<int,int> > q;
bool ok(int x,int y)
{
	return (x>=1&&x<=n&&y>=1&&y<=m);
}
void bfs(int x,int y)
{
	while(!q.empty())
		q.pop();
	q.push(make_pair(x,y));
	mp[x][y]=1;
	while(!q.empty())
	{
		pair<int,int> f=q.front();
		q.pop();
		for(int i=0;i<4;i++)
			if(ok(f.first+tx[i],f.second+ty[i])&&!mp[f.first+tx[i]][f.second+ty[i]])
			{
				mp[f.first+tx[i]][f.second+ty[i]]=1;
				q.push(make_pair(f.first+tx[i],f.second+ty[i]));
			}
				
	}
}
void solve()
{
	n=read();
	m=read();
	g.clear();
	b.clear();
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<m;l++)
		{
			mp[i][l+1]=0; 
			if(s[l]=='G')
				g.push_back(make_pair(i,l+1));	
			if(s[l]=='B')
				b.push_back(make_pair(i,l+1));
			if(s[l]=='#')
				mp[i][l+1]=1;
		}
	}
//	cout<<b.size()<<" "<<g.size()<<endl;
	if(b.size()==0&&g.size()==0)
	{
		puts("YES");
		return ;
	}
	for(auto i:b)
		for(int l=0;l<4;l++)
			if(ok(i.first+tx[l],i.second+ty[l]))
				mp[i.first+tx[l]][i.second+ty[l]]=1;
	for(auto i:g)
		if(mp[i.first][i.second])
		{
			puts("No");
			return ;
		}
	if(mp[n][m])
	{
		if(g.size())
			puts("nO");
		else
			puts("YES");
		return ;
	}
	bfs(n,m);
	for(auto i:g)
		if(!mp[i.first][i.second])
		{
			puts("NO");
			return ;
		}
	puts("YES");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}