#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int n,m,w,cnt,ans,fa[200001],ff[200001];
set<int> st,g[200001];
vector<pair<int,pair<int,int> > > edg;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int find1(int x)
{
	return ff[x]==x?x:ff[x]=find1(ff[x]);
}
void dfs(int x)
{
	st.erase(x);
	for(auto i=st.begin();i!=st.end();)
	{
		int to=*i;
		if(!g[x].count(to))
		{
			cnt--;
			fa[find(x)]=find(to);
			dfs(to);
		}
		i=st.upper_bound(to);
	}
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		w^=z;
		edg.push_back(make_pair(z,make_pair(x,y)));
		g[x].insert(y);
		g[y].insert(x);
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=ff[i]=i;
		st.insert(i);
	}
	cnt=n*(n-1)/2-m;
	for(int i=1;i<=n;i++)
		if(st.count(i))
			dfs(i);
	if(cnt>0)
		w=0;
	sort(edg.begin(),edg.end());
	for(auto i:edg)
	{
		int x=i.second.first,y=i.second.second,z=i.first;
		if(find(x)==find(y))
		{
			if(find1(x)!=find1(y))
			{
				w=min(w,z);
				ff[find1(x)]=find1(y);
			}
		}
		else
		{
			ans+=z;
			fa[find(x)]=find(y);
			ff[find1(x)]=find1(y);
		}
	}
	cout<<ans+w;
	return 0;
}