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

int n,m;
char s[MAXN],t[MAXN];
int dp[5010][5010];
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n>>m>>s>>t;
	for (int i=0;i<=5000;i++)
		for (int j=0;j<=5000;j++)
			dp[i][j]=-INF;
	for (int i=0;i<=5000;i++)
		dp[i][0]=dp[0][i]=-1;
	dp[0][0]=0;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (s[i-1]==t[j-1])
			{
				dp[i][j]=max(dp[i][j],2);
				dp[i][j]=max(dp[i][j],2+dp[i-1][j-1]);
			}
			else
			{
				dp[i][j]=max(dp[i][j],-2);
				dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
				dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
			}
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			ans=max(ans,dp[i][j]);
		}
	cout<<ans;

	return ~~(0^_^0);
}