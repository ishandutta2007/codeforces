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
map<int,int> num;
int t,n,x,ans,a[100001];
void solve()
{
	n=read();
	x=read();
	num.clear();
	ans=0;
	for(int i=1;i<=n;i++)
		num[read()]++;
	if(x==1)
	{
		for(auto i:num)
			ans+=(i.second&1);
		cout<<ans<<'\n';
		return ; 
	}
	for(auto &i:num)
	{
		if(num.find(i.first*x)==num.end())
			continue;
		int k=min(i.second,num[i.first*x]);
		i.second-=k;
		num[i.first*x]-=k;
	}
	for(auto i:num)
		ans+=i.second;
	cout<<ans<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}