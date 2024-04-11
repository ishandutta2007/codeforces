#include<algorithm>
#include<cstring>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1000005,mod=1000000007;
typedef long long LL;
int n,k,head,tail;
LL a,b,y[N],ans;

LL getmi(LL a,int x)
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
	scanf("%d%d",&n,&k),a=b=1;
	rep(i,1,k+1) y[i]=(y[i-1]+getmi(i,k))%mod;
	if(n<=k+1) {printf("%lld\n",y[n]); return 0;}
	rep(i,0,k+1) a=a*(n-i+mod)%mod;
	rep(i,1,k+1) b=b*(mod-i)%mod;
	head=-k-1,tail=-1;
	rep(i,0,k+1)
	{
		ans=(ans+y[i]*a%mod*getmi(n-i+mod,mod-2)%mod*getmi(b,mod-2))%mod;
		if(!(++tail)) tail=1;
		b=b*getmi(head+mod,mod-2)%mod*(tail+mod)%mod;
		if(!(++head)) head=1;
	}
	printf("%I64d\n",ans);
	return 0;
}