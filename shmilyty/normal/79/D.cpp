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
int n,k,m,p[10002],a[101],dis[20][10002],f[1<<20];
vector<int> v;
void solve(int id)
{
	for(int i=1;i<=n+1;i++)
		dis[id][i]=INF;
	dis[id][v[id]]=0;
	queue<int> q;
	q.push(v[id]);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=1;i<=m;i++)
		{
			if(x>=a[i]&&dis[id][x-a[i]]>dis[id][x]+1)
			{
				dis[id][x-a[i]]=dis[id][x]+1;
				q.push(x-a[i]); 
			}
			if(x+a[i]<=n+1&&dis[id][x+a[i]]>dis[id][x]+1)
			{
				dis[id][x+a[i]]=dis[id][x]+1;
				q.push(x+a[i]);
			}
		}
	}
}
signed main()
{
	n=read();
	k=read();
	m=read();
	for(int i=0;i<k;i++)
	{
		int x=read();
		p[x]^=1;
		p[x+1]^=1;
	}
	for(int i=1;i<=n+1;i++)
		if(p[i])
			v.push_back(i);
	k=v.size();
	for(int i=1;i<=m;i++)
		a[i]=read();
	for(int i=0;i<k;i++)
		solve(i);
	for(int i=0;i<(1<<k)-1;i++)
		f[i]=INF;
	for(int i=(1<<k)-1;i;i--)
	{
		int l;
		for(l=0;!((i>>l)&1);l++);
		for(int j=l+1;j<k;j++)
			if((i>>j)&1)
				f[i^(1<<l)^(1<<j)]=min(f[i^(1<<l)^(1<<j)],f[i]+dis[l][v[j]]);
	}
	if(f[0]==INF)
		puts("-1");
	else
		cout<<f[0];
	return 0;
}