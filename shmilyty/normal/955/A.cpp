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
int ti,h,d,c,n;
signed main()
{
	ti=read()*60+read();
	h=read();
	d=read();
	c=read();
	n=read();
	if(ti>=1200)
	{
		double ans=(h+n-1)/n*c*4.0/5.0;
		cout<<ans;
	}
	else
	{
		double ans1=(h+n-1)/n*c,ans2=(h+(1200-ti)*d+n-1)/n*c*4.0/5.0;
		cout<<min(ans1,ans2);
	}
	return 0;
}