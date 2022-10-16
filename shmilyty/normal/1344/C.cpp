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
int n,m,an1,d[200001],f[200001],g[200001];
vector<int> q,G[200001][2];
string an2;
signed main()
{
	n=read();
	m=read();
	while(m--)
	{
		int x=read(),y=read();
		d[y]++;
		G[x][0].push_back(y);
		G[y][1].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!d[i])
			q.push_back(i);
	for(int l=0;l<q.size();l++)
		for(int i:G[q[l]][0])
		{
			d[i]--;
			if(!d[i])
				q.push_back(i);
		}
	if(q.size()!=n)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		f[i]=g[i]=i;
	for(int i:q)
		for(int l:G[i][1])
			f[i]=min(f[i],f[l]);
	for(int i=n-1;i>=0;i--)
		for(int l:G[q[i]][0])
			g[q[i]]=min(g[q[i]],g[l]);
	for(int i=1;i<=n;i++)
	{
		if(min(f[i],g[i])==i)
		{
			an2+='A';
			an1++;
		}
		else
			an2+='E';
	}
	cout<<an1<<'\n'<<an2;
	return 0;
}