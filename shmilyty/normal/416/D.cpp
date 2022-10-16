#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0;
	bool flag=1;
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
int n,a[200001];
int solve(int x)
{
	int c1=0,c2=1,fir=0,sec=0;
	for(int i=x;i<=n&&sec==0;i++)
		if(a[i]>0)
		{
			if(fir)
				sec=i;
			else
				fir=i;
		}
		else
		{
			if(fir)
				c2++;
			else
				c1++;
		}
	if(!sec)
		return 1;
	if(abs(a[fir]-a[sec])%c2)
		return 1+solve(sec);
	int d=(a[sec]-a[fir])/c2;
	if(a[fir]-c1*d<=0)
		return 1+solve(sec);
	for(int i=sec+1;i<=n;i++)
	{
		if(a[i-1]+d<=0)
			return 1+solve(i);
		if(a[i]!=-1)
		{
			if(a[i]!=a[i-1]+d)
				return 1+solve(i);
		}
		else
			a[i]=a[i-1]+d;
	}
	return 1;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	cout<<solve(1);
	return 0;
}