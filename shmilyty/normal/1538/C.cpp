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
int t,n,l,r,a[200001];
void solve()
{
	n=read();
	l=read();
	r=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	int ans=0,L=n,R=n;
	for(int i=1;i<n;i++)
	{
		if(a[i]+a[n]<l||a[i]+a[i+1]>r)
			continue;
		L=max(L,i+1);
		for(;a[L-1]+a[i]>=l&&L>i+1;L--);
		for(;a[R]+a[i]>r;R--);
//		cout<<L<<" "<<R<<endl; 
		ans+=max(0ll,R-L+1);
//		cout<<ans<<endl;
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