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

int n;
LL dp[MAXN];
LL sum[MAXN];
int cnt[MAXN];
void init()
{
	for (int i=2;i<MAXN;i++)
	{
		for (int j=i*2;j<MAXN;j+=i)
			cnt[j]++;
	}
	dp[0]=1;
	sum[0]=1;
	dp[1]=1;
	sum[1]=2;
	for (int i=2;i<MAXN;i++)
	{
		dp[i]=(1+cnt[i]+sum[i-1])%MOD;
		sum[i]=(sum[i-1]+dp[i])%MOD;
		//cout<<i<<' '<<cnt[i]<<' '<<dp[i]<<' '<<sum[i]<<endl;
	}
}

void work()
{
	cin>>n;
	cout<<dp[n]<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}