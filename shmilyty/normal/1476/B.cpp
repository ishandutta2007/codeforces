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
int t,n,k,a[101],f[101];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			f[i]=a[i]+f[i-1];
		}	
		int ans=0;
		for(int i=2;i<=n;i++)
			ans=max(ans,(a[i]*100+k-1)/k-f[i-1]);
		cout<<ans<<endl;
	} 
	return 0;
}