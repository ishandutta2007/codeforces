#include<bits/stdc++.h>
using namespace std;
const int N=405;
long long p2[N],fac[N],rev[N];
long long a[N][N];
int n,MOD;
long long pw(long long x,int y)
{
	long long s=1;
	for(;y;y>>=1,x=x*x%MOD)
		if(y&1)
			s=s*x%MOD;
	return s;
}
int main()
{
    cin>>n>>MOD;
    p2[0]=1;
	for(int i=1;i<=n;i++)
		p2[i]=p2[i-1]*2%MOD;
    fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
    rev[n]=pw(fac[n],MOD-2);
    for(int i=n-1;i!=-1;--i)
		rev[i]=rev[i+1]*(i+1)%MOD;
    a[0][0]=1;
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			for(int k=0;k<j-1;k++)
        		a[i][j]=(a[i][j]+a[i-1][k]*p2[j-k-2]%MOD*rev[j-k-1])%MOD;
    int ans=0;
    // rep(i,n)printf("%lld\n",(ll)a[i][n+1]*fra[n+1-i]%mod);
    for(int i=1;i<=n;i++)
		ans=(ans+a[i][n+1]*fac[n+1-i])%MOD;
    cout<<ans<<endl;
}