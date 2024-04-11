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
int T,n,p;
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(p=1;p*(p+1)<n*2;p++);
		printf("%d\n",p+(p*(p+1)/2-n==1));
	}
	return 0;
}