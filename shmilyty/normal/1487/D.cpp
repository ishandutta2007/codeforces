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
int t,n;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		if(n<5)
		{
			puts("0");
			continue;
		}
		int a=sqrt(2*n-1);
		a=(a-1)/2*2+1;
		while((a*a+1)/2<=n)
			a++;
		while((a*a+1)/2>n)
			a--;
		cout<<(a-3)/2+1<<endl;
	}
	return 0;
}