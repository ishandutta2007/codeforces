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
int t,n,m,a[100001];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		int ans=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			int x=read();
			a[x%m]++;
		}
		for(int i=1;i*2<m;i++)
			if(a[i]==a[m-i]&&a[i]!=0)
				ans++;
			else
				ans+=abs(a[i]-a[m-i]);
		if(a[0])
			ans++;
		if(m%2==0&&a[m/2])
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}