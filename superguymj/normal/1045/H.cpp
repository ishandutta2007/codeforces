#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=100005,mod=1000000007;
char A[N],B[N];
int a,b,c,d,len,la,lb,tot;
int s[N],tmp[N],d0,d1,s0,s1;
typedef long long LL;
LL ans,flv[N],inv[N];

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

LL C(int n,int m)
{
	return n<m?0:flv[n]*inv[m]%mod*inv[n-m]%mod;
}

void pre()
{
	flv[0]=1;
	rep(i,1,la) flv[i]=flv[i-1]*i%mod;
	inv[la]=getmi(flv[la],mod-2);
	repd(i,la,1) inv[i-1]=inv[i]*i%mod;
}

LL calc(int n,int m)
{
	if(n==0 && m==0) return 1;
	if(n<=0 || m<=0) return 0;
	return C(n-1,m-1);
}

LL solve()
{
	if(c==b) d1=c+1,d0=b;
	else if(c==b+1) d1=d0=c;
	else return 0;

	tot=a+b+c+d+1;
	s0=a+b+(d0==d1);
	s1=c+d+(d0!=d1);
	if(s0+s1!=tot) return 0;

	if(len<tot) return 0;
	if(len>tot) return calc(s0,d0)*calc(s1,d1)%mod;
	
	int tot0=0,tot1=1,D0=0,D1=1;

	LL rt=0;

	rep(i,1,len-1)
	{
		if(s[i+1]==1)
		{
			if(s[i]==0)
			{
				rt=(rt+calc(s0-tot0-1,d0-D0)*calc(s1-tot1,d1-D1))%mod;
				rt=(rt+calc(s0-tot0-1,d0-D0+1)*calc(s1-tot1,d1-D1))%mod;
			}
			else
			{
				rt=(rt+calc(s0-tot0-1,d0-D0-1)*calc(s1-tot1,d1-D1))%mod;
				rt=(rt+calc(s0-tot0-1,d0-D0)*calc(s1-tot1,d1-D1))%mod;
			}
		}
	
		if(s[i+1]==1)
		{
			++tot1;
			if(s[i]==0) ++D1;
		}
		if(s[i+1]==0)
		{
			++tot0;
			if(s[i]==1) ++D0;
		}
	}

	if(tot0==s0 && tot1==s1 && D0==d0 && D1==d1) rt=(rt+1)%mod;
	return rt;
}

int main()
{
	scanf("%s",B+1),lb=strlen(B+1);
	scanf("%s",A+1),la=strlen(A+1);
	scanf("%d%d%d%d",&a,&b,&c,&d);

	pre();
	
	rep(i,1,la) s[i]=(A[i]=='1');
	len=la,ans=solve();
	
	rep(i,1,lb) tmp[lb-i+1]=(B[i]=='1');
	--tmp[1];
	rep(i,1,lb) if(tmp[i]<0) tmp[i]+=2,--tmp[i+1];
	len=0;
	rep(i,1,lb) if(tmp[i]) len=i;
	if(len)
	{
		rep(i,1,len) s[len-i+1]=tmp[i];
		ans=(ans-solve()+mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}