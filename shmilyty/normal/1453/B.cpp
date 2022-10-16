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
int t,n,a[200001],ans,maxx;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		ans=maxx=0;
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=2;i<=n;i++)
			ans+=abs(a[i]-a[i-1]);
		maxx=max(abs(a[1]-a[2]),abs(a[n-1]-a[n]));
		for(int i=2;i<n;i++)
			maxx=max(maxx,abs(a[i-1]-a[i])+abs(a[i]-a[i+1])-abs(a[i-1]-a[i+1]));
		cout<<ans-maxx<<endl;
	}
	return 0;
}