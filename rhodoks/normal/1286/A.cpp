#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN];
vector<int> v;
int dp[110][110][110];

int main()
{
	cin>>n;
	MST(dp,INF);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i])
			v.push_back(a[i]&1);
	}
	dp[0][0][0]=dp[0][0][1]=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=min(i,n/2);j++)
		{
			if (a[i]==0)
			{
				dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][0]);
				dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][1]+1);
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+1);
			}
			else if (a[i]&1)
			{
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+1);
			}
			else
			{
				dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][0]);
				dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][1]+1);
				
			}
		}
	cout<<min(dp[n][n/2][0],dp[n][n/2][1]);
	return ~~(0^_^0);
}