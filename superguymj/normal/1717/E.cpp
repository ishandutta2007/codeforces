#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005,mod=1000000007;
typedef long long LL;
int n;
LL mu[N],phi[N],f[N],g[N],ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint();
	mu[1]=1;
	rep(i,1,n)
		for(int j=i+i; j<=n; j+=i)
			mu[j]-=mu[i];
	rep(i,1,n)
		for(int j=i,k=1; j<=n; j+=i,++k)
			phi[j]+=k*mu[i];
	rep(i,1,n)
		for(int j=i,k=1; j<=n; j+=i,++k)
			f[j]=(f[j]+phi[i]*(k-1))%mod;
	rep(i,1,n) if(n%i==0)
		rep(j,1,i-1) g[i]=(g[i]+f[j]*(i-j))%mod;
	rep(i,1,n) if(n%i==0)
		for(int j=i,k=1; j<=n; j+=i,++k)
			if(n%j==0)
				ans=(ans+i*mu[k]%mod*k%mod*k%mod*g[n/i/k])%mod;
	printf("%lld\n",ans);
	return 0;
}