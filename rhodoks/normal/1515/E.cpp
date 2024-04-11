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

#define MAXN 1010
#define MAXM 2010000
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL MOD;
LL n;
LL dp[MAXN][MAXN];
LL C[MAXN][MAXN];
LL pow2[MAXN];
LL fxxk[MAXN];
LL powrec[MAXN][MAXN];
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

void init()
{
	cin>>n>>MOD;
	pow2[0]=1;
	C[0][0]=1;
	for (int i=0;i<=401;i++)
		for (int j=0;j<=401;j++)
		{
			//C[i+1][j]+=C[i][j];
			for (int k=0;k<=401;k++)
			{
				C[i+1][j+k]+=C[i][j];
				C[i+1][j+k]%=MOD;
			}
		}
	for (int i=0;i<MAXN;i++)
		for (int j=0;j<MAXN;j++)
			powrec[i][j]=mpow(i,j);
	for (int i=1;i<=500;i++)
	{
		pow2[i]=(pow2[i-1]+pow2[i-1])%MOD;
		if (pow2[i]>=MOD)
			pow2[i]-=MOD;
	}
}


void work()
{
	LL ans=0;
	for (int i=1;i<=500;i++)
		dp[i][i]=pow2[i-1];
	for (int i=0;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			dp[i][j]%=MOD;
			for (int k=1;k<=n;k++)
				dp[i+k+1][j+k]+=dp[i][j]*(pow2[k-1])%MOD*C[k+1][j]%MOD;
			//dp[i][j]+=dp[i-1][j-1];
		}
	}
	for (int i=0;i<=n;i++)
		ans+=dp[n][i];
	cout<<ans%MOD;
	//dp[3][2]=2;
	//dp[3][3]=2;
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