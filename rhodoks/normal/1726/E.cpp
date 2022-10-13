#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 310000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-8

#define _ 0
using namespace std;
LL dp[MAXN];

LL mpow(LL x,LL n)
{
	LL ans=1;
	while (n)
	{
		if (n&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return ans;
}

LL inv(LL x)
{
	return mpow(x,MOD-2);
}

LL fac[MAXN];
LL pow2[MAXN];
LL tmp[MAXN];
LL fk[MAXN];
LL C(int n,int k)
{
	return fac[n]*inv(fac[k])%MOD*inv(fac[n-k])%MOD;
}
void init()
{
	fac[0]=1;
	pow2[0]=1;
	tmp[0]=1;
	fk[0]=fk[1]=1;
	fk[2]=2;
	for (int i=1;i<MAXN;i++)
	{
		fac[i]=fac[i-1]*i%MOD;
		pow2[i]=pow2[i-1]*2%MOD;
		if (i%2==0)
			tmp[i]=tmp[i-2]*(i/2*2-1)%MOD;
		if (i>=2)
			fk[i]=(fk[i-1]+fk[i-2]*(i-1))%MOD;
	}
}


void work()
{
	int x;
	cin>>x;
	LL ans=0;
	
	for (int i=0;i<=x;i+=4)
	{
		ans+=C(x-i/2,i/2)*tmp[i/2]%MOD*pow2[i/4]%MOD*fk[x-i]%MOD;
	}
	

	cout<<ans%MOD<<endl;
}

int main()
{
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}