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
int t,a,b;
signed main()
{
	t=read();
	while(t--)
	{
		a=read();
		b=read();
		int ans=114514114514114514;
		if(a<b)
		{
			puts("1");
			continue;
		}
		for(int i=b;i<=b+10000;i++)
		{
			if(i==1)
				continue;
			int s=0;
			int aa=a;
			while(aa)
			{
				aa/=i;
				s++;
			}
			ans=min(ans,s+i-b);
			if(i>a)
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}