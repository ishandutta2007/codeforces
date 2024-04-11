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
int n,k,tot,vis[101];
signed main()
{
	tot=n=read();
	k=read();
	int cnt=1;
	for(int i=1;i<=k;i++)
	{
		cnt=(cnt+read()-1)%tot+1;
		int num=0;
		for(int i=1;i<=n;i++)
		{
			num+=1-vis[i];
			if(num==cnt)
			{
				cout<<i<<" ";
				vis[i]=1;
				break;
			}
		}
		tot--;
	}
	return 0;
}