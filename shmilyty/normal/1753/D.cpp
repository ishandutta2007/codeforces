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
const int INF=1e18;
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
std::vector<array<int,2>> G[300001];
priority_queue<array<int,2>> qu;
int n,m,p,q,ans,vis[300001],dis[300001];
string s[300010];
int id(int x,int y)
{
	return (x-1)*m+y;
}
bool ok(int x,int y)
{
	return s[x][y]!='#';
}
void add(int x,int y,int z)
{
	G[x].push_back({y,z});
}
signed main()
{
	n=read();
	m=read();
	q=read();
	p=read();
	for(int i=0;i<=m+1;i++)
		s[0]+="#";
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]="#"+s[i]+"#";
	}
	for(int i=0;i<=m+1;i++)
		s[n+1]+="#";
	fill(dis+1,dis+1+n*m,INF);
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			if(s[i][l]=='.')
			{
				dis[id(i,l)]=0;
				qu.push({0,id(i,l)});
			}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
		{
			if(s[i][l]=='L')
			{
				int x=id(i,l+1);
				if(ok(i-1,l))
					add(id(i-1,l),x,q);
				if(ok(i+1,l))
					add(id(i+1,l),x,q);
				if(ok(i,l-1))
					add(id(i,l-1),x,p);
			}
			if(s[i][l]=='R')
			{
				int x=id(i,l-1);
				if(ok(i-1,l))
					add(id(i-1,l),x,q);
				if(ok(i+1,l))
					add(id(i+1,l),x,q);
				if(ok(i,l+1))
					add(id(i,l+1),x,p);
			}
			if(s[i][l]=='U')
			{
				int x=id(i+1,l);
				if(ok(i,l-1))
					add(id(i,l-1),x,q);
				if(ok(i,l+1))
					add(id(i,l+1),x,q);
				if(ok(i-1,l))
					add(id(i-1,l),x,p);
			}
			if(s[i][l]=='D')
			{
				int x=id(i-1,l);
				if(ok(i,l-1))
					add(id(i,l-1),x,q);
				if(ok(i,l+1))
					add(id(i,l+1),x,q);
				if(ok(i+1,l))
					add(id(i+1,l),x,p);
			}
		}
	while(!qu.empty())
	{
		auto [_,x]=qu.top();
		qu.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(auto [i,l]:G[x])
			if(dis[i]>dis[x]+l)
			{
				dis[i]=dis[x]+l;
				qu.push({-dis[i],i});
			}
	}
	ans=INF;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			if(ok(i,l))
			{
				// cout<<i<<" "<<l<<" "<<dis[id(i,l)]<<'\n';
				if(ok(i+1,l))
					ans=min(ans,dis[id(i,l)]+dis[id(i+1,l)]);
				if(ok(i,l+1))
					ans=min(ans,dis[id(i,l)]+dis[id(i,l+1)]);
			}
	if(ans==INF)
		ans=-1;
	cout<<ans;
	return 0;
}