
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back
#define mp make_pair

using namespace std;
const int N=200005,mod=998244353;
typedef long long LL;
int n,k,a[N];
LL ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL getmi(LL a,LL x)
{
	LL rt=1;
	while(x)
	{
		if(x&1) rt=rt*a%mod;
		a=a*a%mod,x>>=1;
	}
	return rt;
}

void solve()
{
	n=getint(),k=0;
	rep(i,1,n) a[i]=getint(),k+=a[i];
	int x=0,y=0;
	rep(i,1,n-k) if(a[i]==1) ++x;
	rep(i,n-k+1,n) if(a[i]==0) ++y;
	ans=0;
	rep(i,1,x)
		ans=(ans+getmi((LL)i*i%mod,mod-2))%mod;
	ans=ans*n%mod*(n-1)%mod*getmi(2,mod-2)%mod;
	printf("%lld\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}