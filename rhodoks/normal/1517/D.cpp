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

typedef pair<int,int> pii;
int n,m,k;
vector<pii> g[MAXN];
int Emp(int x,int y)
{
	//cout<<x<<' '<<y<<' '<<x*m-m+y<<endl;
	return x*m-m+y;
}

int dp[MAXN][23];
void init()
{

}

void work()
{
	MST(dp,INF);
	cin>>n>>m>>k;
	if (k%2==1)
	{
		for (int i=1;i<=n;i++) 
		{
			for (int j=1;j<=m;j++)
				printf("-1 ");
			printf("\n");
		}
		return;
	}
	int w;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			dp[Emp(i,j)][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<m;j++)
		{
			scanf("%d",&w);
			g[Emp(i,j)].push_back({Emp(i,j+1),w}); 
			g[Emp(i,j+1)].push_back({Emp(i,j),w}); 
		}
	}
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&w);
			g[Emp(i,j)].push_back({Emp(i+1,j),w}); 
			g[Emp(i+1,j)].push_back({Emp(i,j),w}); 
		}
	}
	for (int q=1;q<=k/2;q++)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				for (auto p:g[Emp(i,j)])
				{
					//cout<<Emp(i,j)<<' '<<p.first<<' '<<p.second<<endl;
					//WRT(dp[Emp(i,j)][q-1]+p.second)
					dp[p.first][q]=min(dp[p.first][q],dp[Emp(i,j)][q-1]+p.second);
				}
			}
	}
	//MRK();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			printf("%d ",dp[Emp(i,j)][k/2]*2);
		putchar('\n');
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