#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int t,a,b;
void solve()
{
	a=read();
	b=read();
	if(b==1)
	{
		puts("No");
		return ;
	}
	puts("YES");
	cout<<a*(2*b-1)<<" "<<a<<" "<<a*2*b<<endl;
}
signed main()
{	
	t=read();
	while(t--)
		solve();
	return 0;
}