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
const int INF=4e18;
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
int n,k,ans,a[201],f[201][201][1001];
const int mod=1e9+7;
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	f[0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int l=0;l<n;l++)
		{
			int t=(a[i+1]-a[i])*l;
			for(int j=0;j<=k-t;j++)
			{
				(f[i+1][l][j+t]+=1ll*f[i][l][j]*(l+1)%mod)%=mod;
				if(l!=n)
					(f[i+1][l+1][j+t]+=f[i][l][j])%=mod;
				if(l)
					(f[i+1][l-1][j+t]+=1ll*f[i][l][j]*l%mod)%=mod;
			}
		}
	for(int i=0;i<=k;i++)
		(ans+=f[n][0][i])%=mod;
	cout<<ans;
	return 0;
}