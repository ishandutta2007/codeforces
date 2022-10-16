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
int t,n,a[101];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			a[read()]++;
		for(int i=0;i<=100;i++)
			if(a[i])
			{
				a[i]--;
				cout<<i<<" ";
			}
		for(int i=0;i<=100;i++)
			for(int l=1;l<=a[i];l++)
				cout<<i<<" ";
		cout<<endl; 
	}
	return 0;
}