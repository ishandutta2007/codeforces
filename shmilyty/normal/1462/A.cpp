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
int t,n,a[100001];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i*2<=n;i++)
			cout<<a[i]<<" "<<a[n+1-i]<<" ";
		if(n&1)
			cout<<a[n/2+1]; 
		puts("");
	}
	return 0;
}