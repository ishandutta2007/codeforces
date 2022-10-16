#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0;
	bool flag=1;
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
int n,a[1000001],nxt[1000001],vis[1000001],idx[1000001],ans[1000001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		nxt[i]=a[i]=read();
//	for(int i=1;i<=n;i++)
//		cout<<nxt[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int now=i,num=0;
			while(!vis[now])
			{
				vis[now]=1;
				now=a[now];
				num++;
			}
			if(num&1)
			{
				now=a[i];
				int cnt=a[i];
				for(int i=1;i<=num/2;i++)
					now=a[now];
				ans[i]=now;
				for(int i=1;i<num;i++)
				{
					ans[cnt]=a[now];
					now=a[now];
					cnt=a[cnt];
				}		
			} 
			else
			{
				if(!idx[num])
				{
					idx[num]=i;
					continue;
				}
				int last=idx[num];
				now=i;
				idx[num]=0;
				for(int i=1;i<=num;i++)
				{
					ans[last]=now;
					ans[now]=a[last];
					now=a[now];
					last=a[last];
				}
			}
		}
	for(int i=2;i<=n;i+=2)
		if(idx[i])
		{
			puts("-1");
			return 0;
		}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}