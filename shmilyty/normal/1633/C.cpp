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
int t,h1,d1,h2,d2,k,w,a;
void solve()
{
	h1=read();
	d1=read();
	h2=read();
	d2=read();
	k=read();
	w=read();
	a=read();
	for(int i=0;i<=k;i++)
	{
		int hh=h1+a*i,dd=d1+w*(k-i);
		if((hh+d2-1)/d2>=(h2+dd-1)/dd)
		{
			puts("Yes");
			return ;
		}
	}
	puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}