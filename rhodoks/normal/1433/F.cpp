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

int a[72][72];
int n,m,k;
int dp[72][51][72];
int dp2[2][72];
void work()
{
	MST(dp,-INF);
	//WRT(dp[0][0][0]);
	
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			dp[i][0][0]=0;
			//cout<<i<<' '<<j<<endl;
			cin>>a[i][j];
			for (int ii=m/2;ii>=0;ii--)
				for (int jj=0;jj<k;jj++)
				{
					//cout<<ii<<' '<<jj<<endl;
					dp[i][ii+1][(jj+a[i][j])%k]=max(dp[i][ii+1][(jj+a[i][j])%k],dp[i][ii][jj]+a[i][j]);
				}
		}
	}
	//MRK();
	int cnt=0;
	MST(dp2,-INF);
	dp2[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int t=0;t<k;t++)
			dp2[cnt^1][t]=-INF;
		for (int t=0;t<k;t++)
			for (int ii=m/2;ii>=0;ii--)
				for (int jj=0;jj<k;jj++)
				{
					dp2[cnt^1][(t+jj)%k]=max(dp2[cnt^1][(t+jj)%k],dp2[cnt][t]+dp[i][ii][jj]);
					dp2[cnt^1][t]=max(dp2[cnt^1][t],dp2[cnt][t]);
				}
		cnt^=1;
	}
	cout<<dp2[cnt][0]<<endl;
		
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}