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
int t,n,a[2001];
void solve()
{
	int ans=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		ans^=a[i];
	}
	if(ans==0)
	{
		puts("YES");
		return ;
	}
	int now=0,num=0;
	for(int i=1;i<=n;i++)
	{
		now^=a[i];
		if(now==ans)
		{
			now=0;
			num++;	
		}	
	} 
	if(num>1)
		puts("YES");
	else	
		puts("NO");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}