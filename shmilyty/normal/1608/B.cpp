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
int t,n,a,b,l,r;
void solve()
{
	r=n=read();
	l=1;
	a=read();
	b=read();
	if(a+b+2>n)
	{
		puts("-1");
		return ;
	}
	if(abs(a-b)>1)
	{
		puts("-1");
		return ;
	}
	int ok=0;
	if(a<b)
		ok=1;
	if(ok)
	{
		cout<<n;
		r--;	
	}
	else
	{
		cout<<1;
		l++;
	}
	for(int i=1;i<=a+b;i++)
	{
		if(ok)
		{
			cout<<" "<<l;
			l++;
		}
		else
		{
			cout<<" "<<r;
			r--;
		}
		ok^=1;
	}
	if(!ok)
		for(int i=l;i<=r;i++)
			cout<<" "<<i;
	else
		for(int i=r;i>=l;i--)
			cout<<" "<<i;
	cout<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}