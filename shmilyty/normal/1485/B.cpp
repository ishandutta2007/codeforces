#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
int n,q,k,a[100001],f[100001],s[100001];
signed main()
{
	n=read();
	q=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	a[0]=0;
	a[n+1]=k+1;
	for(int i=1;i<=n;i++)
	{ 
		f[i]=a[i+1]-a[i-1]-2;
		s[i]=s[i-1]+f[i];
	}
	while(q--)
	{
		int x=read(),y=read();
		int ans=s[y-1]-s[x];
		ans+=(a[n+1]-a[y-1]-2);
		ans+=(a[x+1]-a[0]-2);
		cout<<ans<<endl;
	}
	return 0;
}