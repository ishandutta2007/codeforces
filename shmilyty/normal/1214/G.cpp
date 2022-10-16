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
int n,m,q,cnt[500001];
bitset<2002> a[2001],b[2001],tmp;
set<pair<int,int>> ans,s;
set<int> g[2001];
void add(int x,int y)
{
	tmp=a[x]&a[y];
	if(a[x]!=tmp)
	{
		g[x].insert(y);
		g[y].insert(x);
		if(x<y)
			ans.insert({x,y});
		else
			ans.insert({y,x});
	}
}
void solve(int x,int l,int r)
{
	for(int i:g[x])
	{
		g[i].erase(x);
		if(i<x)
			ans.erase({i,x});
		else
			ans.erase({x,i});
	}
	g[x].clear();
	a[x]^=b[r];
	a[x]^=b[l-1];
	auto it=s.find({cnt[x],x});
	int pre=-1,nxt=-1;
	if(it!=s.begin())
	{
		pre=(--it)->second;
		it++;
	}
	it++;
	if(it!=s.end())
		nxt=it->second;
	if(nxt!=-1&&pre!=-1)
		add(pre,nxt);
	s.erase({cnt[x],x});
	cnt[x]=a[x].count();
	it=s.insert({cnt[x],x}).first;
//	s.insert({cnt[x],x});
//	it=s.find({cnt[x],x});
	pre=-1,nxt=-1;
	if(it!=s.begin())
	{
		pre=(--it)->second;
		it++;
	}
	it++;
	if(it!=s.end())
		nxt=it->second;
	if(pre!=-1)
		add(pre,x);
	if(nxt!=-1)
		add(x,nxt);
	if(ans.empty())
	{
		puts("-1");
		return ;
	}
	int x1=ans.begin()->first,x2=ans.begin()->second;
	tmp=a[x1]&a[x2];
	int y1=(a[x1]^tmp)._Find_first(),y2=(a[x2]^tmp)._Find_first();
	if(y1>y2)
		swap(y1,y2);
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<'\n';
}
signed main()
{
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
		s.insert({0,i});
	for(int i=1;i<=m;i++)
	{
		b[i]=b[i-1];
		b[i][i]=1;
	}
	while(q--)
	{
		int c=read(),k=read(),l=read();
		solve(c,k,l);
	}
	return 0;
}