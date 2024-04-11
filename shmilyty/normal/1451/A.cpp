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
int t,n;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		if(n<4)
			cout<<n-1<<endl;
		else
			cout<<2+(n&1)<<endl;
	}
	return 0;
}