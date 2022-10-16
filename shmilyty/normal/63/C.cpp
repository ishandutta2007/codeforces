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
struct node{
	int a[5],b,c;
}q[11];
int n,ans,x[5];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		q[i].a[1]=x/1000;
		q[i].a[2]=(x%1000)/100;
		q[i].a[3]=(x%100)/10;
		q[i].a[4]=x%10;
		q[i].b=read();
		q[i].c=read();
	}
	for(int i=123;i<=9876;i++)
	{
		x[1]=i/1000;
		x[2]=(i%1000)/100;
		x[3]=(i%100)/10;
		x[4]=i%10;
		bool ok=1;
		for(int i=1;i<=4;i++)
			for(int l=i+1;l<=4;l++)
				if(x[i]==x[l])
					ok=0;
		if(ok==0)
			continue;
		ok=1;
		for(int i=1;i<=n;i++)
		{
			int b=0,c=0;
			for(int j=1;j<=4;j++)
				for(int l=1;l<=4;l++)
					if(q[i].a[j]==x[l])
					{
						if(j==l)
							b++;
						else
							c++;
					}
			if(b!=q[i].b||c!=q[i].c)
				ok=0;
		}	
		if(ok)
		{
			if(ans)
			{
				puts("Need more data");
				return 0;
			}
			else
				ans=i;
		}
	}
	if(ans)
		cout<<ans/1000<<(ans%1000)/100<<(ans%100)/10<<ans%10;
	else
		puts("Incorrect data");
	return 0;
}