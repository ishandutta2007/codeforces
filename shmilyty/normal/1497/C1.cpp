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
int t,n,k;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		k=read();
		for(int i=1;i<=k-3;i++)
			cout<<"1 ";
		n-=(k-3);
		if(n%4==0)
			cout<<n/4<<" "<<n/4<<" "<<n/2<<endl;
		else
		{
			if(n%2==0)
				cout<<"2 "<<n/2-1<<" "<<n/2-1<<endl;
			else
				cout<<"1 "<<n/2<<" "<<n/2<<endl;
		}
	}
	return 0;
}