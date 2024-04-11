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
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

#define int LL
char s[2010][2010];
int dp[2010][2010];
int n,m;
int ptr[2010];
LL sum[2010]; 

void inc(int j)
{
	if (ptr[j]<0)
		ptr[j]++;
	else
	{
		sum[j]-=dp[ptr[j]][j];
		sum[j]%=MOD;
		ptr[j]++;
		while (s[ptr[j]][j]!='R' && ptr[j]<=n)
		{
			sum[j]-=dp[ptr[j]][j];
			sum[j]%=MOD;
			//cout<<ptr[j]<<' '<<j<<' '<<sum[j]<<endl;
			ptr[j]++;
		}	
	}	
}

signed main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>s[i]+1;
	if (s[n][m]=='R')
	{
		cout<<0;
		return 0;
	}
	for (int i=1;i<=max(n,m)+1;i++)
		s[0][i]=s[i][0]=s[n+1][i]=s[i][m+1]='#';
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='.')
				ptr[j]--;
	int tmp=0;
	for (int i=1;i<=n;i++)
		if (s[1][i]=='R')
			tmp++;
	//for (int i=1;i<=m;i++)
	//	ptr[i]--;
	dp[0][1]=1;
	sum[1]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			inc(j);
			WRT(ptr[j])
		}
		for (int j=1;j<=m;j++)
			sum[j]%=MOD;
		int res=0;
		
		for (int j=m;j>=1;j--)
		{
			dp[i][j+1]+=sum[j];
			dp[i][j+1]%=MOD;
			dp[i][m-res+1]-=sum[j];
			dp[i][m-res+1]%=MOD;
			if (s[i][j]=='R')
				res++;
		}
		
		for (int j=1;j<=m;j++)
		{
			dp[i][j]+=dp[i][j-1]%MOD;
			dp[i][j]%=MOD;
			sum[j]+=dp[i][j];
			sum[j]%=MOD;
		}
		
	}
	for (int i=n-1;s[i][m]!='R' && i>=0;i--)
		dp[n][m]+=dp[i][m],dp[n][m]%=MOD;
	cout<<(dp[n][m]%MOD+MOD)%MOD<<endl;
	return ~~(0^_^0);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}
}