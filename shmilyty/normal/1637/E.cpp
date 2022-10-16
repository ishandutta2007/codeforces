#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
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
int t,n,m,a[300001],vis[300001];
map<int,int> num;
map<pair<int,int>,bool> ok; 
vector<int> v,v1[300001];
void solve()
{
	n=read();
	m=read();
	fill(a+1,a+1+n,0);
	fill(vis+1,vis+1+n,0);
	v.clear();
	num.clear();
	for(int i=1;i<=n;i++)
		v1[i].clear();
	ok.clear();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		num[a[i]]++;
	}
	sort(a+1,a+1+n);
	int len=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=len;i++)
	{
		int x=num[a[i]];
		if(!vis[x])
		{
			v.push_back(x);
			vis[x]=1;
		}
		v1[x].push_back(a[i]);
	}
	for(int i=1;i<=n;i++)
		sort(ALL(v1[i]),greater<int>());
	sort(ALL(v));
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		ok[{x,y}]=1;
		ok[{y,x}]=1;
	}
	long long ans=0;
	for(int i=1;i<=len;i++)
		for(int l:v)
		{
			if(num[a[i]]<l)
				break;
			int x=num[a[i]]+l;
			for(int j:v1[l])
			{
				if(a[i]==j)
					continue;
				if(ok[{a[i],j}])
					continue;
				ans=max(ans,1ll*x*(a[i]+j));
				break;
			}
		}
	cout<<ans<<'\n';
}
signed main()
{
//	freopen("1.in","r",stdin);
	t=read();
	while(t--)
		solve();
	return 0;
}