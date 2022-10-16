#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int t,n,m,x,y;
void solve()
{
	n=read();
	m=read();
	x=read();
	y=read();
	if(x*y!=1&&x+y!=n*m)
		cout<<"1 1 "<<n<<" "<<m<<endl;
	else
		cout<<"1 "<<m<<" "<<n<<" 1"<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}