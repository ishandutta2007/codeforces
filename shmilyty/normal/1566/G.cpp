#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
using namespace __gnu_pbds;
using myset = tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;
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
int n,m,q;
myset edge;
vector<map<int,int>>mp;
vector<myset>adj;
void solve()
{
	auto [z,p]=*edge.begin();
	int x=p/(n+1),y=p%(n+1);
	int m1=1e18,mn=1e18;
	vector<pair<int,int>> v1,v2;
	for(auto i:adj[x])
		if(i.second!=y)
		{
			v1.push_back(i);
			if(v1.size()>=2)
				break;
		}
	for(auto i:adj[y])
		if(i.second!=x)
		{
			v2.push_back(i);
			if(v2.size()>=2)
				break;
		}
	if(v1.size()==2)
		m1=min(m1,z+v1[0].first+v1[1].first);
	if(v2.size()==2)
		m1=min(m1,z+v2[0].first+v2[1].first);
	for(auto i:v1)
		for(auto l:v2)
			if(i.second!=l.second)
				m1=min(m1,i.first+l.first);
	int l=z,r=edge.rbegin()->first;
	while(l<r)
	{
		int mid=(l+r)>>1;
		int c1=adj[x].order_of_key({mid+1,0ll});
		int c2=adj[y].order_of_key({mid+1,0ll});
		int c3=edge.order_of_key({mid+1,0ll});
		if(c3>c1+c2-1)
		{
			r=mid;
			mn=r;
		}
		else
			l=mid+1;
	}
	int c1=adj[x].order_of_key({l+1,0ll});
	int c2=adj[y].order_of_key({l+1,0ll});
	int c3=edge.order_of_key({l+1,0ll});
	if(c3>c1+c2-1)
		mn=l;
	cout<<min(m1,z+mn)<<endl;
}
signed main()
{
    n=read();
    m=read();
    vector<map<int,int>>a1(n+1);
    vector<myset>a2(n+1);
    mp=a1;
    adj=a2;
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		if(x>y)
			swap(x,y);
		adj[x].insert({z,y});
		adj[y].insert({z,x});
		edge.insert({z,x*(n+1)+y});
		mp[x][y]=mp[y][x]=z;
	}
	q=read();
	solve();
	while(q--)
	{
		int opt=read(),x=read(),y=read();
		if(x>y)
			swap(x,y);
		if(opt)
		{
			int z=read();
			adj[x].insert({z,y});
			adj[y].insert({z,x});
			edge.insert({z,x*(n+1)+y});
			mp[x][y]=mp[y][x]=z;
		}
		else
		{
			int z=mp[x][y];
			edge.erase({z,x*(n+1)+y});
			adj[x].erase({z,y});
			adj[y].erase({z,x});
		}
		solve();
	}
// 	*/
	return 0;
}