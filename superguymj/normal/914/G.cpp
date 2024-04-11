#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=1000005,lim=(1<<17)-1,mod=1000000007;
int n,a[N],bin[N];
LL ans,inv2,A[N],B[N],C[N],f[N];
LL f1[20][N],f2[N],fib[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void inc(LL &x,LL y)
{
	x=(x+y)%mod;
}

void task1()
{
	rep(i,1,lim) bin[i]=bin[i^(i&-i)]+1;
	rep(i,1,n) ++f1[bin[a[i]]][a[i]];
	rep(i,0,17)
		rep(j,0,17)
			rep(k,0,lim)
				if(!(k&(1<<j)))
					inc(f1[i][k^(1<<j)],f1[i][k]);
	repd(i,17,0)
		rep(j,0,lim)
		{
			LL tmp=0;
			rep(k,0,i) inc(tmp,f1[k][j]*f1[i-k][j]);
			f1[i][j]=tmp;
		}
	rep(i,0,17)
		rep(j,0,17)
			rep(k,0,lim)
				if(!(k&(1<<j)))
					inc(f1[i][k^(1<<j)],mod-f1[i][k]);
	rep(i,0,lim) A[i]=f1[bin[i]][i]*fib[i]%mod;
}

void task2()
{
	rep(i,1,n) inc(B[a[i]],fib[a[i]]);
}

void FWT(LL a[],int len,int tp)
{
	for(int i=1; i<len; i<<=1)
		for(int j=0; j<len; j+=i<<1)
			rep(k,0,i-1)
			{
				LL x=a[j+k],y=a[i+j+k];
				if(tp==1) a[j+k]=(x+y)%mod,a[i+j+k]=(x-y+mod)%mod;
				else a[j+k]=(x+y)*inv2%mod,a[i+j+k]=(x-y+mod)*inv2%mod;
			}
}

void task3()
{
	rep(i,1,n) ++f2[a[i]];
	FWT(f2,lim+1,1);
	rep(i,0,lim) f2[i]=f2[i]*f2[i]%mod;
	FWT(f2,lim+1,-1);
	rep(i,0,lim) C[i]=f2[i]*fib[i]%mod;
}

void task4()
{
	rep(i,0,17)
		rep(j,0,lim)
			if(j&(1<<i))
			{
				inc(A[j^(1<<i)],A[j]);
				inc(B[j^(1<<i)],B[j]);
				inc(C[j^(1<<i)],C[j]);
			}
	rep(i,0,lim) f[i]=A[i]*B[i]%mod*C[i]%mod;
	rep(i,0,17)
		rep(j,0,lim)
			if(j&(1<<i))
				inc(f[j^(1<<i)],mod-f[j]);
}

int main()
{
	n=getint(),fib[1]=1,inv2=(mod+1)/2;
	rep(i,1,n) a[i]=getint();
	rep(i,2,lim) fib[i]=(fib[i-1]+fib[i-2])%mod;
	task1(),task2(),task3(),task4();
	rep(i,0,16) ans=(ans+f[1<<i])%mod;
	printf("%lld\n",ans);
	return 0;
}