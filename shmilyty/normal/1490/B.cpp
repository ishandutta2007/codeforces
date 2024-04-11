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
int t,n,a,ans,c1,c2,c3;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		ans=c3=c1=c2=0;
		for(int i=1;i<=n;i++)
		{
			a=read();
			switch(a%3)
			{
				case 0:{
					c1++;
					break;
				}
				case 1:{
					c2++;
					break;
				}
				case 2:{
					c3++;
					break;
				}
			}
		}
		if(c1>n/3)
		{
			c2+=c1-n/3;
			ans+=c1-n/3;
			c1=n/3;
		}
		if(c2>n/3)
		{
			c3+=c2-n/3;
			ans+=c2-n/3;
			c2=n/3;
		}
		if(c3>n/3)
		{
			c1+=c3-n/3;
			ans+=c3-n/3;
			c3=n/3;
		}
		if(c1>n/3)
		{
			c2+=c1-n/3;
			ans+=c1-n/3;
			c1=n/3;
		}
		if(c2>n/3)
		{
			c3+=c2-n/3;
			ans+=c2-n/3;
			c2=n/3;
		}
		cout<<ans<<endl;
	}
	return 0;
}