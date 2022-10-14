#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<x<<endl;

#define MAXN 605000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,x;
LL a[MAXN];
LL dp[MAXN][3];
int main()
{
	LL mx=0;
	cin>>n>>x;
	RPT(i,0,n)
		cin>>a[i];
	dp[0][0]=max((LL)0,a[0]);
	dp[0][1]=max((LL)0,x*a[0]);
	dp[0][2]=0;
	RPT(j,0,3)
		if (dp[0][j]>mx)
			mx=dp[0][j];
	RPT(i,1,n)
	{
		dp[i][0]=max((LL)0,dp[i-1][0]+a[i]);
		dp[i][1]=max((LL)0,dp[i-1][0]+x*a[i]);
		dp[i][1]=max(dp[i][1],dp[i-1][1]+x*a[i]);
		dp[i][2]=max((LL)0,dp[i-1][2]+a[i]);
		dp[i][2]=max(dp[i][2],dp[i-1][1]+a[i]);
		dp[i][2]=max(dp[i][2],dp[i-1][0]+a[i]);
		RPT(j,0,3)
			if (dp[i][j]>mx)
				mx=dp[i][j];
	}
	cout<<mx;
	return ~~(0^_^0);
}