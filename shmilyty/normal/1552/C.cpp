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
int t,n,k,vis[201];
vector<int> v;
pair<int,int> p[101];
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=2*n;i++)
		vis[i]=0;
	v.clear();
	for(int i=1;i<=k;i++)
	{
		int x=read(),y=read();
		p[i]={x,y};
		vis[x]=1;
		vis[y]=1;
	}
	for(int i=1;i<=2*n;i++)
		if(!vis[i])
			v.push_back(i);
	for(int i=0;i<n-k;i++)
		p[i+k+1]={v[i],v[i+n-k]};
	int ans=0;
	for(int i=1;i<=n;i++)
		if(p[i].first>p[i].second)
			swap(p[i].first,p[i].second);
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			if(p[i].first<p[l].first&&p[l].first<p[i].second&&p[i].second<p[l].second)
				ans++;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}