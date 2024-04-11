#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
const int mod=998244353;
int n,k,f[250][251],C[251][251],p[251][251];
int qp(int x,int y)
{
	return p[x][y];
}
signed main()
{
	n=read();
	k=read();
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int l=1;l<=i;l++)
			C[i][l]=(C[i-1][l]+C[i-1][l-1])%mod;
	}
	for(int i=1;i<=k;i++)
	{
		p[i][0]=1;
		for(int l=1;l<=n;l++)
			p[i][l]=p[i][l-1]*i%mod;
	}
	f[0][0]=1;
	for(int i=1;i<n;i++)
		for(int l=1;l<=k;l++)
			for(int ll=0;ll<l;ll++)
			{
				int cnt=1;
				for(int j=i;j;j--)
				{
					(cnt*=qp(k-l+1,j-1))%=mod;
					(f[i][l]+=f[j-1][ll]*C[i][j-1]%mod*cnt%mod)%=mod;
				}
			}
//	for(int i=1;i<=k;i++)
//		cout<<f[n-1][i]<<endl;
	int ans=0;
//	for(int i=1;i<=k;i++)
//		cout<<f[n-1][i]<<endl;
	for(int i=1;i<=k;i++)
		(ans+=f[n-1][i])%=mod;
	cout<<ans; 
	return 0;
}