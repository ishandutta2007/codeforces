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
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;



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
	return fac[n]*invfac[x]%MOD*invfac[n-x]%MOD;
}

void init()
{
	fac_init();
}

char s[MAXN];
int n;
void work()
{
	cin>>n>>s;
	int cnt0=0,cnt11=0,cnt10=0;
	for (int i=0;i<n;)
	{
		if (s[i]=='1' && (s[i+1]=='0'))
		{
			cnt10++;
			i++;
		}
		else if (s[i]=='1' && (s[i+1]=='1'))
		{
			cnt11++;
			i++;
		}
		else if (s[i]=='0')
			cnt0++;
		i++;
		
	}
	//cout<<cnt0<<' '<<cnt10<<' '<<cnt11<<endl;
	cout<<getC(cnt10+cnt11+cnt0,cnt11)<<endl;
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