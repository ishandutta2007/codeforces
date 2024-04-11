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
int t,n,a[200001],b[200001];
vector<int> pos[200001],val[200001],v,v1;
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		pos[i].clear();
	v.clear();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		pos[a[i]].push_back(i);
		val[i].clear();
	}
	for(int i=1;i<=n;i++)
		val[pos[i].size()].push_back(i);
	for(int i=1;i<=n;i++)
		if(!val[i].empty())
			v.push_back(i);
	for(int i=1;i<=n;i++)
	{
		v1.clear();
		for(int l:v)
			if(l>=i)
				for(int j:val[l])
				{
					v1.push_back(pos[j].back());
					pos[j].pop_back();
				}
		if(!v1.empty())
		{
			for(int l=1;l<v1.size();l++)
				b[v1[l]]=a[v1[l-1]];
			b[v1[0]]=a[v1.back()];
		}
	}
	for(int i=1;i<=n;i++)
		cout<<b[i]<<' ';
	cout<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}