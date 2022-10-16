#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int n,ans=0,cnt,a[501],f[503][503];
const int mod=998244353;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='+')
			a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
			continue;
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int l=1;l<=n;l++)
			for(int j=0;j<=n;j++)
			{
				if(l>i&&!j)
					continue;
				if(l!=i)
					(f[l][j]+=f[l-1][j])%=mod;
				if(l<=i&&a[l])
				{
					if(a[l]<=a[i]&&j)
						(f[l][j]+=f[l-1][j-1])%=mod;
					if(a[l]>a[i])
						(f[l][j]+=f[l-1][j])%=mod;
				}
				if(l>i&&a[l])
				{
					if(a[l]<a[i]&&j)
						(f[l][j]+=f[l-1][j-1])%=mod;
					if(a[l]>=a[i])
						(f[l][j]+=f[l-1][j])%=mod;	
				}
				if(!a[l])
				{
					(f[l][j]+=f[l-1][j+1])%=mod;
					if(l<i&&!j)
						(f[l][j]+=f[l-1][j])%=mod;
				}
			}
		for(int l=1;l<=n;l++)
			(ans+=1ll*f[n][l]*a[i]%mod)%=mod;
	}
	cout<<ans;
	return 0;
}