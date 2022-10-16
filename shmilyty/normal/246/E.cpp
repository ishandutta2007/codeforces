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
int n,cnt,m,l[100001],r[100001],d[100001];
vector<int> G[100001],p[200001];
string s[100001];
map<array<int,2>,int> mp;
void dfs(int x,int y)
{
	p[y].push_back(x);
	l[x]=++cnt;
	d[x]=y;
	for(int i:G[x])
		dfs(i,y+1);
	r[x]=cnt;
}
int q(int x,int y)
{
//	cout<<x<<" "<<y<<endl;
	int L=1,R=(int)p[x].size();
//	for(int i:p[x])
//		cout<<i<<" ";
//	cout<<endl;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(l[p[x][mid-1]]<=y)
			L=mid+1;
		else
			R=mid-1;
	}
//	cout<<"L: "<<L<<endl;
	return L-1;
}
void solve()
{
	int x=read(),y=read()+d[x];
	if(mp[{x,y}])
	{
		cout<<mp[{x,y}]<<endl;
		return ;
	}
	int L=q(y,l[x]),R=q(y,r[x]);
	set<string> qu;
	for(int i=L;i<R;i++)
		qu.insert(s[p[y][i]]);
	mp[{x,y}]=qu.size();
	cout<<qu.size()<<endl;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		G[read()].push_back(i);
	}
	dfs(0,0);
	m=read();
	while(m--)
		solve();
	return 0;
}