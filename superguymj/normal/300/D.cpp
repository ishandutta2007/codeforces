#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=5005,mod=7340033;
typedef long long LL;
int q,n,k,x,len,bin[N];
LL a[N],f[305][N];

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

void prepare()
{
	for(len=1; len<=4000; len<<=1);
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
	f[0][0]=1;
	rep(nw,1,300)
	{
		memcpy(a,f[nw-1],sizeof(a));
		FFT(a,len,1);
		rep(i,0,len-1) a[i]=a[i]*a[i]%mod,a[i]=a[i]*a[i]%mod;
		FFT(a,len,-1),f[nw][0]=1;
		rep(i,1,1000) f[nw][i]=a[i-1];
	}
}

int main()
{
	prepare(),q=getint();
	while(q--)
	{
		n=getint(),k=getint(),x=0;
		while(n>1)
			if(n&1) ++x,n>>=1;
			else break;
		printf("%lld\n",f[x][k]);
	}
	return 0;
}