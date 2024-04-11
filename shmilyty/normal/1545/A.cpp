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
int t,n,a[100001];
pair<int,int> b[100001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		b[i]={read(),i};
	sort(b+1,b+1+n);
	int o1=0,o2=0,e1=0,e2=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i].first!=b[i-1].first)
			if(o1!=o2)
			{
				puts("No");
				return ; 
			}
		if(i&1)
			o1++;
		else
			e1++;
		if(b[i].second&1)
			o2++;
		else
			e2++;
	}
	puts("Yes");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}