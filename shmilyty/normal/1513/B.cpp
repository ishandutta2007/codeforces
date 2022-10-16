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
const int mod=1e9+7;
int t,n,x,jiechen[200001],a[200001];
void solve()
{
	n=read();
	x=(1ll<<32)-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		x&=a[i];
	}
	int num=0;
	for(int i=1;i<=n;i++)
		if(a[i]==x)
			num++;
	cout<<((num-1)*num)%mod*jiechen[n-2]%mod<<endl;
}
signed main()
{
	jiechen[0]=1;
	for(int i=1;i<=200000;i++)
		jiechen[i]=jiechen[i-1]*i%mod;
	t=read();
	while(t--)
		solve();
	return 0;
}