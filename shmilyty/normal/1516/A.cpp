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
int t,n,k,a[101];
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
		{
			if(a[i]>=k)
			{
				a[n]+=k;
				a[i]-=k;
				k=0;
			}
			else
			{
				k-=a[i];
				a[n]+=a[i];
				a[i]=0;
			}
		}
		cout<<a[i]<<" ";
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