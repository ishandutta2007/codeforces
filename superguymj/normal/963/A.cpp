#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int mod=1000000009;
typedef long long LL;
char s[1000005];
int n,k,m;
LL a,b,ans,p;

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
	scanf("%d%d%d%d",&n,&a,&b,&k);
	scanf("%s",s),p=getmi(b,k)*getmi(getmi(a,k),mod-2)%mod;
	LL A=getmi(a,n),B=1,inva=getmi(a,mod-2);
	rep(i,0,k-1)
		ans=(ans+(s[i]=='-'?-1:1)*A*B)%mod,A=A*inva%mod,B=B*b%mod;
	m=(n+1)/k;
	if(m)
	{
		if(p==1) ans=ans*m;
		else ans=(ans*getmi(p,m)-ans)%mod*getmi(p-1,mod-2)%mod;
	}
	else
	{
		ans=0;
		A=getmi(a,n),B=1;
		rep(i,0,n)
			ans=(ans+(s[i]=='-'?-1:1)*A*B)%mod,A=A*inva%mod,B=B*b%mod;
		printf("%lld\n",(ans%mod+mod)%mod);
		return 0;
	}
	if(n-m*k>=0)
	{
		A=getmi(a,n-m*k),B=getmi(b,m*k);
		rep(i,m*k,n)
			ans=(ans+(s[i%k]=='-'?-1:1)*A*B)%mod,A=A*inva%mod,B=B*b%mod;
	}
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}