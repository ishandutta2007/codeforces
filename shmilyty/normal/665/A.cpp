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
int a,ta,b,tb,x,y,t; 
signed main()
{
	a=read();
	ta=read();
	b=read();
	tb=read();
	scanf("%lld:%lld",&x,&y);
	t=60*x+y;
	int l=t-tb,r=t+ta,ans=0;
	for(int i=300;i<=1439;i+=b)
		if(i>l&&i<r)
			ans++;
	cout<<ans<<endl;
	return 0;
}