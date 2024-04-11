#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=33005,mod=998244353;
int n,m,len,bin[N<<1];
LL a[N<<1],b[N<<1],c[N<<1],A[N<<1],B[N<<1],g[N],f[N];

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

void mul1()
{
	rep(i,0,len-1) A[i]=B[i]=0;
	rep(i,0,m) A[i]=g[i],B[i]=f[i];
	FFT(A,len,1),FFT(B,len,1);
	rep(i,0,len-1) a[i]=A[i]*A[i]%mod,b[i]=B[i]*B[i]%mod,c[i]=A[i]*B[i]*2%mod;
	FFT(a,len,-1),FFT(b,len,-1),FFT(c,len,-1);
	rep(i,1,m) g[i]=(a[i]+b[i-1])%mod,f[i]=(c[i]-b[i-1]-b[i]+mod*2)%mod;
	f[0]=g[0]=1;
}

void mul2()
{
	repd(i,m,1)
		f[i]=g[i],g[i]=(g[i]+g[i-1]+f[i-1])%mod;
	f[0]=g[0]=1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(len=1; len<=m*2; len<<=1);
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
	g[0]=1;
	for(int i=1<<30,nw=0; i; i>>=1)
	{
		if(nw) mul1(),nw<<=1;
		if(n&i) mul2(),++nw;
	}
	rep(i,1,m) printf("%lld ",g[i]);
	puts("");
	return 0;
}