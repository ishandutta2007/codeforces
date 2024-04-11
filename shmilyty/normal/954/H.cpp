#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
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
int n,a[5001],b[5001],f[5001][10001],ans[10001];
const int mod=1e9+7;
signed main()
{
	n=read();
	b[0]=1;
	for(int i=1;i<n;i++)
	{
		a[i]=read();
		b[i]=(1ll*a[i]*b[i-1])%mod;
	}
	for(int i=n;i;i--)
	{
		f[i][0]=1;
		for(int l=1;l<=n-i;l++)
		{
			f[i][l]=1ll*f[i+1][l-1]*a[i]%mod;
			(ans[l]+=1ll*f[i][l]*b[i-1]%mod)%=mod;
		}
	}
	for(int i=1;i<=n;i++)
		for(int l=i+n-2;l;l--)
		{
			f[i][l]=f[i-1][l-1];
			if(i>1&&l>1&&l-2<=n-i)
				(f[i][l]+=1ll*f[i][l-2]*(a[i-1]-1)%mod)%=mod;
			(ans[l]+=1ll*f[i][l]*b[i-1]%mod)%=mod;
		}
	for(int i=1;i<=2*n-2;i++)
		cout<<1ll*ans[i]*(mod+1)/2%mod<<" ";
	return 0;
}