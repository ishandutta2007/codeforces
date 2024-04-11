#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=1000005,mod=104857601;
bool vis[N];
int n,m,len,bin[N<<2],p[N],a[N],ans[N];
LL f[N<<2];

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

int main()
{
	n=getint(),m=getint(),f[0]=1;
	rep(i,1,n) f[p[i]=getint()]=1;
	for(len=1; len<=m*2; len<<=1);
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
	FFT(f,len,1);	
	rep(i,0,len-1) f[i]=f[i]*f[i]%mod;
	FFT(f,len,-1);
	rep(i,1,n) a[p[i]]=1;
	rep(i,1,m) if(a[i] && !f[i] || !a[i] && f[i]) return puts("NO"),0;
	rep(i,1,m) f[i]-=a[i]*2;	

	rep(i,1,n)
		if(a[p[i]] && !f[p[i]])
		{
			ans[++*ans]=p[i];
			for(int j=p[i]; j<=m; j+=p[i]) vis[j]=1;
		}

	puts("YES"),printf("%d\n",*ans);
	rep(i,1,*ans-1) printf("%d ",ans[i]);	
	printf("%d\n",ans[*ans]);
	return 0;
}