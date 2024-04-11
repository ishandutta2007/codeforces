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

#define MAXN 1010000
#define MAXM 2010000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL dp[MAXN];
int n,k;


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


LL fac[MAXN+3];
LL invfac[MAXN+3];

void fac_init(int n=MAXN)
{
	fac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	invfac[n]=inv(fac[n]);
	for (int i=n;i;i--)
		invfac[i-1]=invfac[i]*i%MOD;
}

LL getC(int n,int x)
{
	if (n<=0 || x<=0 || x>n)
		return 0;
	return fac[n]*invfac[x]%MOD*invfac[n-x]%MOD;
}

void init()
{
	fac_init();
}


void work()
{
	cin>>n>>k;
	LL ans=1;
	LL prob=1;
	for (int p=1;n-(k-1)*(p-1)>=p;p++)
	{
		prob*=p;
		prob%=MOD;
		prob*=inv(n-p+1);
		prob%=MOD;
		ans+=prob*getC(n-(k-1)*(p-1),p)%MOD;
	} 
	cout<<ans%MOD<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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