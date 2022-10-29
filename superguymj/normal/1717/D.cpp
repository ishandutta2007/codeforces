#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005,mod=1000000007;
typedef long long LL;
int n,k;
LL flv[N],inv[N],ans;

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

LL C(int n,int m) {return flv[n]*inv[m]%mod*inv[n-m]%mod;}

int main()
{
	n=getint(),k=min(n,getint());
	flv[0]=inv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod,inv[i]=getmi(flv[i],mod-2);
	rep(i,0,k) ans=(ans+C(n,i))%mod;
	printf("%lld\n",ans);
	return 0;
}