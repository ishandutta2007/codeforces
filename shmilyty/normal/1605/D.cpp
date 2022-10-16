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
int t,n,lst,ans[200001],vis[20],lg[200001],fa[400001];
vector<int> v1,v2;
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
#define lowbit(x) (x&(-x))
void solve()
{
	n=read();
	for(int i=1;i<=2*n;i++)
		fa[i]=i;
	fill(ans+1,ans+1+n,0);
	for(int i=0;i<20;i++)
		vis[i]=0;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		fa[find(x+n)]=find(y);
		fa[find(y+n)]=find(x);
	}
	v1.clear();
	v2.clear(); 
	for(int i=1;i<=n;i++)
		if(find(i)==find(1))
			v1.push_back(i);
		else
			v2.push_back(i);
	if(v1.size()>v2.size())
		swap(v1,v2);
	int m=v1.size(),l=0;
	for(int x=0;x<20;x++)
	if((m>>x)&1)
	{
		vis[x]=1;
		for(int i=l;i<l+(1<<x);i++)
			ans[v1[i]]=i-l+(1<<x);
		l+=(1<<x);
	}
	l=0;
	for(int i=1;i<=n;i++)
		if(!vis[lg[i]])
			ans[v2[l++]]=i;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main()
{
	for(int i=2;i<=2e5;i++)
		lg[i]=lg[i>>1]+1;
	t=read();
	while(t--)
		solve();
	return 0;
}