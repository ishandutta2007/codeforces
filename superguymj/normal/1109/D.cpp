#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1000005,mod=1000000007;
typedef long long LL;
int n,m,a,b;
LL ans,flv[N<<1],inv[N<<1];
LL pwk,invk;

LL C(int n,int m)
{
	return n<m?0:flv[n]*inv[m]%mod*inv[n-m]%mod;
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

void pre()
{
	flv[0]=1;
	rep(i,1,m+n) flv[i]=flv[i-1]*i%mod;
	inv[m+n]=getmi(flv[m+n],mod-2);
	repd(i,m+n,1) inv[i-1]=inv[i]*i%mod;
}

LL calc_line(int x)
{
	return C(n-2,x-2)*C(m-1,x-2)%mod*flv[x-2]%mod;
}

LL calc_tree(int x)
{
	return x*pwk%mod*getmi(m,n-x)%mod;
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	pre();
	if(n==2) pwk=getmi(n,mod-2);
	else pwk=getmi(n,n-3);
	invk=getmi(n,mod-2);
	rep(i,2,n)
	{
		ans=(ans+calc_line(i)*calc_tree(i))%mod;
		pwk=pwk*invk%mod;
	}
	printf("%lld\n",ans);
	return 0;
}