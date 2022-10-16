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
int t,n,sum,num,a[100001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	sum=0;
	num=n-1;
	for(int i=0;num>0;i++,num-=2)
		sum+=num*(a[n-i]-a[i+1]);
	cout<<a[n]-sum<<endl;
} 
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}