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

#define MAXN 210000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,x;
int a[MAXN];
int dp[MAXN];
void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]++,dp[x]++; 
	}
	int ans=0;
	for (int i=1;i<MAXN;i++)
	{
		 
		ans=max(ans,dp[i]);
		for (int j=2*i;j<MAXN;j+=i)
		{
			dp[j]=max(dp[j],a[j]+dp[i]);
		}
	}
	for (int i=1;i<MAXN;i++)
		a[i]=dp[i]=0;
	cout<<n-ans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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