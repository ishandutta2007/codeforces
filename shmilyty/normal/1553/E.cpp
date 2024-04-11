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
vector<int> ans;
int t,n,m,p[300001],cnt[300001],fa[300001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++)
		cnt[i]=0;
	for(int i=1;i<=n;i++)
	{
		p[i]=read();
		cnt[(i+n-p[i])%n]++;
	}
	ans.clear();
	for(int i=0;i<n;i++)
	{
		if(cnt[i]<n-2*m)
			continue;
		for(int l=1;l<=n;l++)
			fa[l]=l;
		for(int l=1;l<=i;l++)
			fa[find(p[l])]=find(n-i+l);
		for(int l=i+1;l<=n;l++)
			fa[find(p[l])]=find(l-i);
		int num=n;
		for(int i=1;i<=n;i++)
			if(fa[i]==i)
				num--;
		if(num<=m)
			ans.push_back(i);
	}
	cout<<ans.size()<<" ";
	for(int i:ans)
		cout<<i<<" ";
	cout<<endl; 
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}