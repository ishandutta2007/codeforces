#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=250005,mod=998244353;
int n,bin[N<<2],len;
LL m,a[N<<2],b[N<<2];
LL flv[N],inv[N],f[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL getLL()
{
	char ch;
	while(!isdigit(ch=getchar()));
	LL x=ch-48;
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
				x=a[j+k],y=a[i+j+k]*w,w=w*wn%mod;
				a[j+k]=(x+y)%mod,a[i+j+k]=(x-y)%mod;
			}
		}
	}
	if(tp==-1)
	{
		LL x=getmi(len,mod-2);
		rep(i,0,len-1) a[i]=a[i]*x%mod;
	}
}

int main()
{
	n=getint(),m=getLL();
	
	flv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod;
	inv[n]=getmi(flv[n],mod-2);
	repd(i,n,1) inv[i-1]=inv[i]*i%mod;

	for(len=1; len<=n+n; len<<=1);
	rep(i,0,n) a[i]=getint()*flv[i]%mod,b[n-i]=inv[i];
	FFT(a,len,1),FFT(b,len,1);
	rep(i,0,len-1) a[i]=a[i]*b[i]%mod;
	FFT(a,len,-1);

	rep(i,0,n) f[i]=a[i+n]*getmi(getmi(i+1,mod-2),m)%mod;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int tp=1;
	rep(i,0,n) a[i]=f[i],b[n-i]=inv[i]*tp,tp*=-1;
	FFT(a,len,1),FFT(b,len,1);
	rep(i,0,len-1) a[i]=a[i]*b[i]%mod;
	FFT(a,len,-1);

	rep(i,0,n) printf("%lld ",(a[i+n]*inv[i]%mod+mod)%mod);
	puts("");
	return 0;
}