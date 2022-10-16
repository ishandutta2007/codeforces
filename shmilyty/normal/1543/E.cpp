#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int t,n,a[1<<16],vis[1<<16],dis[1<<16],col[1<<16];
vector<int> v[1<<16];
void solve()
{
	n=read();
	for(int i=0;i<(1<<n);i++)
	{
		dis[i]=INF;
		a[i]=0;
		vis[i]=0;
		v[i].clear();
	}
	for(int i=0;i<n*(1<<(n-1));i++)
	{
		int x=read(),y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<int> q;
	dis[0]=0;
	q.push(0);
	for(int i=0;i<n;i++)
		vis[v[0][i]]=(1<<i);
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		for(int i:v[f])
		{
			if(dis[f]+1<dis[i])
			{
				q.push(i);
				dis[i]=dis[f]+1;
			}
			if(dis[i]==dis[f]+1)
				vis[i]|=vis[f];
		}
	}
	for(int i=0;i<(1<<n);i++)
		a[vis[i]]=i;
	for(int i=0;i<(1<<n);i++)
		cout<<a[i]<<" ";
	cout<<endl;
	if(__builtin_popcount(n)!=1)
	{
		puts("-1");
		return ;
	}
	for(int i=0;i<(1<<n);i++)
	{
		int x=0;
		for(int l=0;l<n;l++)
			x^=l*((i>>l)&1);
		col[a[i]]=x;
	}
	for(int i=0;i<(1<<n);i++)
		cout<<col[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}