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
int n,m,cur,pre,ans,a[200001];
map<int,int> mp;
int solve(int x)
{
	mp.clear();
	cur=n;
	pre=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		mp[cur]++;
		if(a[i]>=x)
			pre+=mp[cur++];
		else
			pre-=mp[--cur];
		ans+=pre;
	}
	return ans;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	cout<<solve(m)-solve(m+1);
	return 0;
}