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
struct que{
	int val;
	array<int,2> a;
	bool operator < (const que& a)const{
		return val>a.val;
	}
};
priority_queue<que> q;
int t,n,k,dis[501][501];
int tx[4]={1,0,-1,0};
int ty[4]={0,1,0,-1};
bool ok(int xx,int yy)
{
	return (xx>=0&&yy>=0&&xx<=k&&yy<=k);
}
map<array<int,4>,int> mp;
vector<array<int,3>> G[501][501];
void solve()
{
	n=read();
	k=read();
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read(),x1=read(),y1=read();
		mp[{x,y,x1,y1}]++;
		mp[{x1,y1,x,y}]++;
		mp[{k+1-x,k+1-y,k+1-x1,k+1-y1}]++;
		mp[{k+1-x1,k+1-y1,k+1-x,k+1-y}]++;
	}
	for(int i=0;i<=k;i++)
		for(int l=0;l<=k;l++)
		{
			G[i][l].clear();
			for(int j=0;j<4;j++)
			{
				int x=i+tx[j],y=l+ty[j];
				if(!ok(x,y))
					continue;
				if(j&1)
					G[i][l].push_back({x,y,mp[{i,max(y,l),i+1,max(y,l)}]});
				else
					G[i][l].push_back({x,y,mp[{max(x,i),l,max(x,i),l+1}]});
			}
		}
	for(int i=0;i<=k;i++)
		for(int l=0;l<=k;l++)
			dis[i][l]=INF;
	dis[k/2][k/2]=0;
	q.push({0,{k/2,k/2}});
	while(!q.empty())
	{
		auto x=q.top().a;
		int v=q.top().val;
		q.pop();
		if(dis[x[0]][x[1]]!=v)
			continue;
		for(auto i:G[x[0]][x[1]])
			if(dis[i[0]][i[1]]>v+i[2])
			{
				dis[i[0]][i[1]]=v+i[2];
				q.push({v+i[2],{i[0],i[1]}});
			}
	}
	int ans=INF;
	for(int i=0;i<=k;i++)
		for(int l=0;l<=k;l++) 
			if((!i)||(!l)||l==k||i==k)
				ans=min(ans,dis[i][l]);
	cout<<n-ans<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}