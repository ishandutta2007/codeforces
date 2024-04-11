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
struct node{
	int to,val;
	bool operator<(const node &x)const
	{
		return val>x.val;
	}
};
int t,n,k,d[400001],vis[400001],dis[400001];
queue<int> q;
vector<int> G[400001];
void solve()
{
	n=read();
	k=read();
	if(n==1)
	{
		puts("0");
		return ;
	}
	fill(d+1,d+1+n,0);
	fill(dis+1,dis+1+n,INF);
	fill(vis+1,vis+1+n,0);
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	for(int i=1;i<=n;i++)
		if(d[i]==1)
		{
			dis[i]=0;
			d[i]--;
			q.push(i);
		}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i:G[x])
			if(d[i])
			{
				d[i]--;
				if(d[i]==1)
				{
					dis[i]=dis[x]+1;
					q.push(i); 
				}
			}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(dis[i]>=k)
			ans++;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}