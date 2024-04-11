#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)

using namespace std;
const int N=1000005,mod=1000000007;
const int inv2=(mod+1)/2;
typedef long long LL;
int n;
LL bin[N],pw[N];
LL g[N],s[N],ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve()
{
	n=getint();
	if(n==1)
	{
		puts("1");
		return;
	}
	puts("0");
	g[n+1]=s[n+1]=0;
	g[n]=s[n]=2;
	repd(i,n-1,1)
	{
		int r=min(n+1,i*2);
		g[i]=(s[i+1]-s[r]+mod)%mod;
		s[i]=(s[i+1]+g[i])%mod;
	}
	rep(i,2,n)
	{
	//	ans=bin[(i+1)/2];
	//	ans=ans*g[i]%mod;
	//	if(i<n) ans=ans*bin[n-i-1]%mod;
		ans=g[i]*pw[i>>1]%mod*bin[n]%mod;
		printf("%lld\n",ans);
	}
}

int main()
{
	n=1000000;
	bin[0]=pw[0]=1;
	rep(i,1,n) pw[i]=pw[i-1]*2%mod,bin[i]=bin[i-1]*inv2%mod;
	int T=getint();
	while(T--) solve();
	return 0;
}