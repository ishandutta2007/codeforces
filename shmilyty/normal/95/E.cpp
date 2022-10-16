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
int n,m,fa[100001],size[100001],cnt[100001],dp[100001];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool isl(int x)
{
	for(;x;x/=10)
		if(x%10!=4&&x%10!=7)
			return 0;
	return 1;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	while(m--)
	{
		int x=read(),y=read();
		fa[find(x)]=find(y);	
	}	
	for(int i=1;i<=n;i++)
		size[find(i)]++;
	for(int i=1;i<=n;i++)
		cnt[size[i]]++;
	for(int i=1;i<=n;i++)
		dp[i]=114514114514114514;
	for(int i=1;i<=n;i++)
		if(cnt[i])
		{
			int num=cnt[i];
			for(int p=1;num;p<<=1)
			{
				p=min(p,num);
				num-=p;
				int w=p*i;
				for(int l=n-w;l>=0;l--)
					dp[l+w]=min(dp[l+w],dp[l]+p);
			}
		}
	int ans=114514114514114514;
	for(int i=1;i<=n;i++)
		if(isl(i))
			ans=min(ans,dp[i]);
	if(ans==114514114514114514)
		ans=-1;
	else
		ans--;
	cout<<ans;
	return 0;
}