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
int t,n,a[10001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	cout<<3*n<<endl;
	for(int i=1;i<=n;i+=2)
	{
		cout<<1<<" "<<i<<" "<<i+1<<endl;
		cout<<2<<" "<<i<<" "<<i+1<<endl;
		cout<<1<<" "<<i<<" "<<i+1<<endl;
		cout<<1<<" "<<i<<" "<<i+1<<endl;
		cout<<2<<" "<<i<<" "<<i+1<<endl;
		cout<<1<<" "<<i<<" "<<i+1<<endl;
	}
} 
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}