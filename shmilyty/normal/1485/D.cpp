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
int n,m,a;
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
		{
			a=read();
			if((i+l)&1)
				cout<<a*a*a*a+720720<<" ";
			else
				cout<<720720<<" "; 
		}
		cout<<endl;
	}
	return 0;
}