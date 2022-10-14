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

#define MAXN 1100
#define MAXM 10000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL dp[MAXN][MAXN][2];

LL n;

LL dfs(LL a,LL b,LL x)
{
	if (b>a)
		return 0;
	if (a>n)
		return 0;
	if (a==n && b==n)
		return 0;
	if (dp[a][b][x]!=0)
		return dp[a][b][x];
	LL ans=0;
	if (x==0)
	{
		ans+=max(dfs(a+1,b,1),dfs(a+1,b,0));
		ans+=max(dfs(a,b+1,1),dfs(a,b+1,0));
		ans%=MOD;
		return dp[a][b][x]=ans;
	}
	else
	{
		ans+=dfs(a+1,b,0);
		ans+=dfs(a,b+1,0);
		if (b<=a+1 && a+1<=n || b+1<=a && a<=n)
			ans+=1;
		ans%=MOD;
		return dp[a][b][x]=ans;
	}
}

int main()
{
	cin>>n;
	dp[n][n-1][0]=0;
	dp[n][n-1][1]=1;
	cout<<max(dfs(0,0,0),dfs(0,0,1));
	return ~~(0^_^0);
}