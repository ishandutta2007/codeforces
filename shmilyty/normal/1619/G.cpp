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
int t,n,k,fa[200001],b[200001];
map<int,vector<pair<int,int>>> mp1,mp2;
array<int,3> a[200001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool check(int x)
{
	int num=0;
	for(int i=1;i<=n;i++)
		if(find(i)==i&&b[i]>x)
			num++;
	if(num<=x+1)
		return 1;
	return 0;
}
void solve()
{
	n=read();
	k=read();
	mp1.clear();
	mp2.clear();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read(),z=read();
		a[i]={x,y,z};
		mp1[x].push_back({y,i});
		mp2[y].push_back({x,i});
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(auto i:mp1)
	{
		vector<pair<int,int>> v=i.second;
		sort(ALL(v));
		for(int l=1;l<v.size();l++)
			if(v[l].first-k<=v[l-1].first)
				fa[find(v[l].second)]=find(v[l-1].second);
	}
	for(auto i:mp2)
	{
		vector<pair<int,int>> v=i.second;
		sort(ALL(v));
		for(int l=1;l<v.size();l++)
			if(v[l].first-k<=v[l-1].first)
				fa[find(v[l].second)]=find(v[l-1].second);
	}
	fill(b+1,b+1+n,INF);
	for(int i=1;i<=n;i++)
		b[find(i)]=min(b[find(i)],a[i][2]);
	int l=0,r=INF;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}