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
int t,n,m,k;
void solve()
{
	n=read();
	m=read();
	k=read();
	if(n%2==0&&m%2==0)
	{
		if(k&1)
			puts("NO");
		else
			puts("YES");
		return ;
	}
	int kk=n*m/2-k;
	if(n&1)
	{
		m/=2;
		if(kk&1)
			puts("NO");
		else
		if(m%2==k%2&&k>=m)
			puts("YES");
		else
			puts("NO");
		return ;
	}
	n/=2;
	if(k&1)
		puts("NO");
	else
	if(n%2==kk%2&&kk>=n)
		puts("YES");
	else
		puts("NO");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}