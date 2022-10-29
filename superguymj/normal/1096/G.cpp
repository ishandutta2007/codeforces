#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1<<20,mod=998244353;
typedef long long LL;
int n,k,bin[N],len;
LL ans,a[N];

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
	n=getint()>>1,k=getint();
	while(k--) ++a[getint()];
	for(len=1; len<=9*n; len<<=1);
	FFT(a,len,1);
	rep(i,0,len-1) a[i]=getmi(a[i],n);
	FFT(a,len,-1);
	rep(i,0,len-1) ans=(ans+a[i]*a[i])%mod;
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}