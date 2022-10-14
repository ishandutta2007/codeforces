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

LL inv(LL x)
{
	return mpow(x,MOD-2);
}

int n,k,N;

LL Cn[2010];
LL ans[2010];
LL C[2010][1010];
int dp[410][305][410];
LL fac[2010];
LL invp[2010];
void init()
{
	fac[0]=1;
	for (int i=1;i<=410;i++)
	{
		fac[i]=fac[i-1]*i%MOD; 
		invp[i]=inv(i);
	}
	for (int i=0;i<410;i++)
		C[i][i]=C[i][0]=1;
	for (int i=1;i<410;i++)
		for (int j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
}

LL Cni[410][410];

void getCni()
{
	for (int i=0;i<410;i++)
	{
		Cni[i][0]=1;
		//C_{n-i}{j}
		for (int j=1;j<410;j++) 
		{
			Cni[i][j]=Cni[i][j-1]*(n-i-j+1)%MOD*inv(j)%MOD;
		}
	}
}

void work()
{

	cin>>n>>k;
	getCni();
	dp[0][0][1]=1;
	N=min(n,2*k);
	WRT(N);
	for (int i=2;i<=N;i++)
	{
		for (int j=0;j<=N;j++)
			for (int t=0;t<=j/2;t++)
			{
				LL tmp=1;
				dp[j][t][i]+=dp[j][t][i-1]%MOD;
				for (int p=1;p<=(N-j)/i;p++)
				{
					//WRT(tmp);
				//	WRT(p)
					//tmp=tmp*C[n-j-p*i+i][i]%MOD*invp[p]%MOD*fac[i]%MOD*invp[i]%MOD;
					//exit(-1);
					//cout<<j+p*i-i<<' '<<i<<' '<<Cni[j+p*i-i][i]<<endl; 
					tmp=tmp*Cni[j+p*i-i][i]%MOD*invp[p]%MOD*fac[i]%MOD*invp[i]%MOD;
					//if (j+p*i>N || t+p>N/2)
					//	continue;
					dp[j+p*i][t+p][i]=((LL)dp[j+p*i][t+p][i]+tmp*dp[j][t][i-1])%MOD;
					//cout<<i<<' '<<j<<' '<<t<<' '<<p<<' '<<j+p*i<<' '<<t+p<<' '<<dp[j+p*i][t+p][i]<<endl;
				}
				//cout<<i<<' '<<j<<' '<<t<<' '<<dp[j][t][i]<<endl;
			}
	}
	Cn[0]=1;
	for (int i=1;i<=min(n,2*k);i++)
	{
		Cn[i]=Cn[i-1]*(n-i+1)%MOD*inv(i)%MOD;
		//WRT(Cn[i]);
	}
	for (int i=0;i<=k;i++)
	{
		for (int j=i;j<=min(n,2*k+1);j++)
		{
			//WRT(j-i);
			if (j-i<=min(n,k+100))
				ans[i]+=dp[j][j-i][N]%MOD;
			//WRT(dp[j][j-i][N]);
		}
		ans[i]%=MOD;
		//WRT(i);
		//WRT(ans[i]); 
	}
	MRK();
	for (int i=1;i<=k;i++)
	{
		LL tmp=0;
		for (int j=i;j>=0;j-=2)
			tmp+=ans[j]; 
		cout<<tmp%MOD<<' ';
	}
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