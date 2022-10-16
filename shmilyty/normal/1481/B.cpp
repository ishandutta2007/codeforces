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
int t,n,k,a[101];
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	int flag=0;
	while(flag==0)
	{
		flag=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]>=a[i+1])
				continue;
			flag=0;
			k--;
			a[i]++;
			if(k==0)
			{
				cout<<i<<endl;
				return ;
			}
			break;
		}
	}
	puts("-1");
	return ;
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}