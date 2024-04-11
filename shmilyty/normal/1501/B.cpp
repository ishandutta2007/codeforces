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
int t,n,a[200001],ans[200001];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
			a[i]=read();
		int cnt=n;
		for(int i=n;i>=1;i--)
			if(a[i])
			{
				int m=max(1ll,i-a[i]+1);
				for(int j=min(cnt,i);j>=m;j--) 
					ans[j]=1;
				cnt=min(cnt,m);
			}
		for(int i=1;i<=n;i++) 
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}