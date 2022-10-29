#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mid (l+r>>1)

using namespace std;
const int N=400005,mod=998244353;
typedef long long LL;
int n,m,a,b,len,bin[N];
LL tmpl[N],tmpr[N],flv[N],inv[N],ans;
vector <LL> A[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
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
	return n<m?0:flv[n]*inv[m]%mod*inv[n-m]%mod;
}

void solve(int l,int r)
{
	if(l==r)
	{
		A[l].pb(1),A[l].pb(l);
		return;
	}
	solve(l,mid),solve(mid+1,r);
	for(len=1; len<=r-l+1; len<<=1);
	rep(i,0,len-1) tmpl[i]=tmpr[i]=0;
	rep(i,0,mid-l+1) tmpl[i]=A[l][i];
	rep(i,0,r-mid) tmpr[i]=A[mid+1][i];
	FFT(tmpl,len,1),FFT(tmpr,len,1);
	rep(i,0,len-1) tmpl[i]=tmpl[i]*tmpr[i]%mod;
	FFT(tmpl,len,-1),A[l].clear();
	rep(i,0,r-l+1) A[l].pb(tmpl[i]);
}

int main()
{
	scanf("%d%d%d",&n,&a,&b),m=n-a-b+1;
	if(m<0 || a==0 || b==0) return puts("0"),0;
	if(n==1)
	{
		if(a==1 && b==1) puts("1");
		else puts("0");
		return 0;
	}
	flv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod;
	inv[n]=getmi(flv[n],mod-2);
	repd(i,n,1) inv[i-1]=inv[i]*i%mod;
	solve(0,n-2);
	ans=A[0][m]*C(a-1+b-1,a-1)%mod;
	printf("%I64d\n",ans);
	return 0;
}