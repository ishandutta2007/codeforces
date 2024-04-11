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
const int mod=1e9+7;
int n,q,ans,c[101],b[101],L[101],f[101][10001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		c[i]=read();
	for(int i=1;i<n;i++)
		b[i]=b[i-1]+read();
	q=read();
	while(q--)
	{
		int x=read(),cnt=0,sum=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			L[i]=max(0ll,x*i+cnt);	
			cnt+=b[i];
		} 
		f[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			sum+=c[i];
			for(int l=L[i];l<=sum;l++)
			{
				for(int j=0;j<=l&&j<=c[i];j++)
					(f[i][l]+=f[i-1][l-j])%=mod;
				if(i==n)
					(ans+=f[i][l])%=mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}