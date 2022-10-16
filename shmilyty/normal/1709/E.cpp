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
int n,ans,a[200001];
std::vector<int> G[200001];
set<int> dfs(int x,int fa,int dep)
{
	set<int> s;
	s.clear();
	s.insert(dep);
	bool ok=1;
	for(int i:G[x])
		if(i!=fa)
		{
			set<int> y=dfs(i,x,dep^a[i]);
			if(!ok)
				continue;
			if(s.size()<y.size())
				swap(s,y);
			for(int l:y)
				if(s.count(l^a[x]))
				{
					s.clear();
					ans++;
					ok=0;
					break;
				}
			if(!ok)
				continue;
			for(int l:y)
				s.insert(l);
		}
	return s;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0,a[1]);
	cout<<ans;
	return 0;
}