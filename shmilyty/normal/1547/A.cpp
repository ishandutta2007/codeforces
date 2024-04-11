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
int t,tx,ty,ax,ay,bx,by; 
void solve()
{
	ax=read();
	ay=read();
	bx=read();
	by=read();
	int ans=abs(ax-bx)+abs(ay-by);
	tx=read();
	ty=read();
	if(tx==ax&&tx==bx)
	{
		if(ay<ty&&ty<by)
			ans+=2;
		if(ay>ty&&ty>by)
			ans+=2;
	}
	if(ty==ay&&ty==by)
	{
		if(ax<tx&&tx<bx)
			ans+=2;
		if(ax>tx&&tx>bx)
			ans+=2;
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}