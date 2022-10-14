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
int a[MAXN];
int dp[MAXN];
vector<int> g[MAXN];
int cnt[MAXN];
int sum[MAXN];
int lst[MAXN]; 
int lstnt[MAXN];
void init()
{

}

void work()
{
	MST(dp,INF);
	int midp=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]!=a[i-1])
			lstnt[i]=a[i-1];
		else
			lstnt[i]=lstnt[i-1];
		if (g[a[i]].size())
			lst[i]=g[a[i]].back();
		g[a[i]].push_back(i);
	}
	dp[0]=0;
	
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];
		if (a[i]!=a[i-1])
			sum[i]++;
	}
	for (int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+1;
		if (lst[i])
		{
			dp[i]=min(dp[i],dp[lst[i]]+sum[i-1]-sum[lst[i]]-(lstnt[lst[i]]==a[lst[i]+1]));
			dp[i]=min(dp[i],dp[lst[i]+1]+sum[i-1]-sum[lst[i]+1]);
		}
		
		//cout<<i<<' '<<a[i]<<' '<<dp[i]<<endl;
	}
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