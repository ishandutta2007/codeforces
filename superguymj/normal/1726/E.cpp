#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=300005,mod=998244353;
int n,len,bin[N<<2];
LL flv[N],inv[N],fflv[N],ans;
LL a[N<<2],b[N<<2];

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

void FFT(LL a[],int len,int tp)
{
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
	rep(i,0,len-1) if(i<bin[i]) swap(a[i],a[bin[i]]);
	for(int i=1; i<len; i<<=1)
	{
		LL wn=getmi(3,(mod-1)/(i<<1));
		if(tp==-1) wn=getmi(wn,mod-2);
		for(int j=0; j<len; j+=i<<1)
		{
			LL w=1,x,y;
			rep(k,0,i-1)
			{
				x=a[j+k],y=a[i+j+k]*w%mod,w=w*wn%mod;
				a[j+k]=(x+y)%mod,a[i+j+k]=(x-y+mod)%mod;
			}
		}
	}
	if(tp==-1)
	{
		LL x=getmi(len,mod-2);
		rep(i,0,len-1) a[i]=a[i]*x%mod;
	}
}

LL C(int n,int m)
{
	return flv[n]*inv[m]%mod*inv[n-m]%mod;
}

LL get(int x)
{
	int y=x>>1;
	return fflv[y]*C(n-y,y)%mod*getmi(2,y>>1)%mod;
}

void solve()
{
	n=getint();
	flv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod;
	inv[n]=getmi(flv[n],mod-2);
	repd(i,n,1) inv[i-1]=inv[i]*i%mod;
	fflv[0]=1;
	rep(i,1,n) if(!(i&1)) fflv[i]=fflv[i-2]*(i-1)%mod;
	
	for(len=1; len<=n+n; len<<=1);
	rep(i,0,len-1) a[i]=b[i]=0;
	rep(i,0,n) a[i]=fflv[i]*inv[i]%mod,b[i]=inv[i];
	FFT(a,len,1),FFT(b,len,1);
	rep(i,0,len-1) a[i]=a[i]*b[i]%mod;
	FFT(a,len,-1);

	ans=0;
	rep(i,0,n)
		if(i%4==0)
			ans=(ans+get(i)*a[n-i]%mod*flv[n-i])%mod;
	printf("%lld\n",ans);
}

int main()
{
	int t=getint();
	while(t--) solve();
	return 0;
}