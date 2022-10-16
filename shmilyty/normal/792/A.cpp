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
int n,ans=114514114514114514,num,a[200001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)	
		ans=min(ans,a[i+1]-a[i]);
	cout<<ans<<" ";
	for(int i=1;i<n;i++)
		if(a[i+1]-a[i]==ans)
			num++;
	cout<<num;
	return 0;
}