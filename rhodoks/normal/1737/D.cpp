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

#define MAXN 510
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-8

#define _ 0
using namespace std;

int dis[MAXN][MAXN];
int g[MAXN][MAXN];
int u[MAXM],v[MAXM];
LL w[MAXM];
int n,m;
void init()
{

}

void work()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			dis[i][j]=INF;
			dis[i][i]=0;
		}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&u[i],&v[i],&w[i]);
		g[u[i]][v[i]]=g[v[i]][u[i]]=dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	LL ans=LLINF;
	for (int i=1;i<=m;i++)
	{
		ans=min(ans,w[i]*(dis[1][u[i]]+dis[v[i]][n]+1));
		ans=min(ans,w[i]*(dis[1][v[i]]+dis[u[i]][n]+1));
		for (int j=1;j<=n;j++)
		{
			ans=min(ans,w[i]*(dis[1][j]+dis[n][j]+dis[v[i]][j]+2));
			ans=min(ans,w[i]*(dis[1][j]+dis[n][j]+dis[u[i]][j]+2));
		}
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}