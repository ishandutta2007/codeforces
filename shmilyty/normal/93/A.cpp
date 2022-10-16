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
int n,m,a,b;
signed main()
{
	n=read();
	m=read();
	a=read();
	b=read();
	int ans=0;
	if((a-1)/m==(b-1)/m)
	{
		puts("1");
		return 0; 
	}
	if((b-a+1)%m==0)
	{
		puts(b%m?"2":"1");
		return 0;
	}
	if(a%m==1&&(b%m==0||b==n))
	{
		puts("1");
		return 0;
	}
	if(a%m==1||(b%m==0||b==n))
		puts("2");
	else
	{
		if((b-1)/m==(a-1)/m+1)
			puts("2");
		else
			puts("3");
	}
	return 0;
}