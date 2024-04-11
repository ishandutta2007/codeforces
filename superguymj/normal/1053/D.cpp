#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=2000005,mod=1000000007;
bool jdg,tp[N];
int n,cnt[N],a[N],ct[N];
typedef long long LL;
LL ans;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

LL getLL()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void fuck(int x)
{
	int lim=sqrt(x);
	rep(i,2,lim) if(x%i==0)
	{
		int c=0;
		while(x%i==0) ++c,x/=i;
		if(c>a[i]) a[i]=c,ct[i]=1;
		else if(c==a[i]) ++ct[i];
	}
	if(x>1)
	{
		if(!a[x]) a[x]=1,ct[x]=1;
		else if(a[x]==1) ++ct[x];
	}
}

void check(int x)
{
	int lim=sqrt(x);
	bool add=0;
	rep(i,2,lim) if(x%i==0)
	{
		int c=0;
		while(x%i==0) ++c,x/=i;
		if(c==a[i] && ct[i]==1) add=1;
	}
	if(x>1 && a[x]==1 && ct[x]==1) add=1;
	if(!add) jdg=1;
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

int main()
{
	n=getint(),ans=1;
	rep(i,1,n) ++cnt[getint()];

	rep(i,2,2000000) if(cnt[i]>=2)
		fuck(i),fuck(i-1),jdg|=cnt[i]>2;

	repd(i,2000000,2) if(cnt[i]==1)
		if(!a[i]) fuck(i),tp[i]=1;
		else fuck(i-1);

	rep(i,2,2000000) if(cnt[i]>=2)
		check(i),check(i-1);

	rep(i,2,2000000) if(cnt[i]==1)
		if(tp[i]) check(i);
		else check(i-1);

	rep(i,2,2000000) ans=ans*getmi(i,a[i])%mod;
	printf("%lld\n",(ans+jdg)%mod);
	return 0;
}