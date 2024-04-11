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
int t,n,a[101],b[101];
void solve()
{
	n=read();
	for(int i=1;i<=2*n;i++)
		a[i]=read();
	sort(a+1,a+1+n*2);
	int l=1,r=n*2;
	while(l<r)
	{
		cout<<a[l]<<" "<<a[r]<<" ";
		l++,r--;
	}
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}