#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005,M=1<<17,mod=998244353,inv2=(mod+1)/2;
int n,k,len,A[N],B[N],C[N];
LL a,b,c,f[M],mxt[M][4][5];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void FWT(LL a[],int len)
{
	for(int i=1; i<len; i<<=1)
		for(int j=0; j<len; j+=i<<1)
			rep(k,0,i-1)
			{
				LL x=a[j+k],y=a[i+j+k];
				a[j+k]=(x+y)%mod,a[i+j+k]=(x-y)%mod;
			}
}

void IFWT(LL a[],int len)
{
	for(int i=1; i<len; i<<=1)
		for(int j=0; j<len; j+=i<<1)
			rep(k,0,i-1)
			{
				LL x=a[j+k],y=a[i+j+k];
				a[j+k]=(x+y)*inv2%mod;
				a[i+j+k]=(x-y)*inv2%mod;
			}
}

void _Q()
{
	memset(f,0,sizeof(f));
	rep(i,1,n) ++f[B[i]^C[i]];
	FWT(f,1<<k);
	rep(i,0,(1<<k)-1)
	{
		mxt[i][0][0]=1;
		mxt[i][0][1]=-1;
		mxt[i][0][2]=-1;
		mxt[i][0][3]=1;
		mxt[i][0][4]=f[i];
	}
}

void Q(int tp,int a,int b,int c)
{
	memset(f,0,sizeof(f));
	rep(i,1,n) f[0]=(f[0]+a)%mod,f[B[i]]=(f[B[i]]+b)%mod,f[C[i]]=(f[C[i]]+c)%mod;
	FWT(f,1<<k);
	rep(i,0,(1<<k)-1)
	{
		mxt[i][tp][0]=(a+b+c)%mod;
		mxt[i][tp][1]=(a+b-c)%mod;
		mxt[i][tp][2]=(a-b+c)%mod;
		mxt[i][tp][3]=(a-b-c)%mod;
		mxt[i][tp][4]=f[i];
	}
}

LL getmi(LL a,LL x)
{
	a%=mod;
	LL rt=1;
	while(x)
	{
		if(x&1) rt=rt*a%mod;
		a=a*a%mod,x>>=1;
	}
	return rt;
}

void gause(int x)
{
	rep(i,0,3)
	{
		int p=i;
		rep(j,i,3) if(mxt[x][j][i]) {p=j; break;}
		rep(j,0,4) swap(mxt[x][i][j],mxt[x][p][j]);
		LL inv=getmi(mxt[x][i][i],mod-2);
		rep(j,0,4) mxt[x][i][j]=mxt[x][i][j]*inv%mod;
		rep(j,0,3) if(i!=j)
		{
			LL t=mxt[x][j][i];
			rep(k,0,4) mxt[x][j][k]=(mxt[x][j][k]-t*mxt[x][i][k])%mod;
		}
	}
}

void solve()
{
	memset(f,0,sizeof(f));
	rep(i,0,(1<<k)-1)
	{
		f[i]=1;
		f[i]=f[i]*getmi(a+b+c,mxt[i][0][4])%mod;
		f[i]=f[i]*getmi(a+b-c,mxt[i][1][4])%mod;
		f[i]=f[i]*getmi(a-b+c,mxt[i][2][4])%mod;
		f[i]=f[i]*getmi(a-b-c,mxt[i][3][4])%mod;
	}
	IFWT(f,1<<k);
	int p=0;
	rep(i,1,n) p^=A[i];
	rep(i,0,(1<<k)-1) printf("%lld ",(f[i^p]+mod)%mod);
	puts("");
}

int main()
{
	n=getint(),k=getint();
	a=getint(),b=getint(),c=getint();
	rep(i,1,n) A[i]=getint(),B[i]=getint()^A[i],C[i]=getint()^A[i];
	_Q();
	Q(1,0,0,1);
	Q(2,0,1,0);
	rep(i,0,(1<<k)-1)
	{
		mxt[i][3][4]=n;
		rep(j,0,3) mxt[i][3][j]=1;
	}
	rep(i,0,(1<<k)-1) gause(i);
	solve();
	return 0;
}