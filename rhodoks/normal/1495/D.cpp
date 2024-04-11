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
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> g[MAXN];
int dis[MAXN][MAXN];
int n,m,x,y;
void init()
{

}

void work()
{
	cin>>n>>m;
	MST(dis,INF);
	for (int i=0;i<m;i++)
	{
		cin>>x>>y;
		dis[x][y]=dis[y][x]=1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		dis[i][i]=0;
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			int cnt=0;
			for (int k=1;k<=n;k++)
				if (dis[i][k]+dis[k][j]==dis[i][j])
					cnt++;
			LL ans=0;
			if (cnt==dis[i][j]+1)
			{
				ans=1;
				for (int k=1;k<=n;k++)
					if (dis[i][k]+dis[k][j]!=dis[i][j])
					{
						int cnt=0;
						for (auto p:g[k])
							if (dis[i][p]==dis[i][k]-1 && dis[j][p]==dis[j][k]-1)
								cnt++;
						ans=ans*cnt%MOD;
					}
			}
			cout<<ans<<' ';
		}
		cout<<endl;
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