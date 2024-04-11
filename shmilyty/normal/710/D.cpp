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
int L,R,a1,b1,a2,b2,X,Y,ans;
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
signed main()
{
	a1=read();
	b1=read();
	a2=read();
	b2=read();
	L=read();
	R=read();
	int d1=exgcd(a1,a2,X,Y),lcm=a1/d1*a2;
	L=max({L,b1,b2});
	if((b2-b1)%d1!=0||L>R)
	{
		cout<<0;
		return 0;
	}
	X*=(b2-b1)/d1;
	X=(X%(a2/d1)+a2/d1)%(a2/d1);
	int x=a1*X+b1;
	if(R>=x)
		ans+=(R-x)/lcm+1;
	if(L-1>=x)
		ans-=(L-1-x)/lcm+1;
	cout<<ans;
	return 0;
}