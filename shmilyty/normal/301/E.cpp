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
const int mod=1e9+7;
int n,m,k,ans,C[101][101],f[51][51][51][101];
signed main()
{
	C[0][0]=1;
	for(int i=1;i<=100;i++)
	{
		C[i][0]=1;
		for(int l=1;l<=i;l++)
			C[i][l]=min(101ll,C[i-1][l]+C[i-1][l-1]);
	}
	n=read();
	m=read();
	k=read();
	n/=2;
	for(int i=1;i<=n;i++)
		f[i][i][1][1]=1;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			for(int j=1;j<=min(n,m);j++)
				for(int p=1;p<=k;p++)
					if(f[i][l][j][p])
					{
						(ans+=(m-j)*f[i][l][j][p]%mod)%=mod;
						for(int q=1;q<=n-i;q++)
							if(p*C[l+q-1][q]<=k)
								(f[q+i][q][j+1][p*C[l+q-1][q]]+=f[i][l][j][p])%=mod;
					}
	cout<<ans;
	return 0;
}