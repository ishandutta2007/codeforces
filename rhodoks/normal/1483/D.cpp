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

#define MAXN 610
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL d[MAXN][MAXN];
LL g[MAXN][MAXN];
LL trip[MAXN][MAXN];
int n,m,x,y,w,q;
LL tmp[MAXN];
void init()
{

}

void work()
{
	MST(d,INF);
	MST(g,INF);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		g[x][y]=g[y][x]=d[x][y]=d[y][x]=w;
	}
	for (int i=1;i<=n;i++)
		g[i][i]=0;
	for (int k=1;k<=n;k++)	
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		/*
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<g[i][j]<<' ';
		cout<<endl;
	}
	*/
	cin>>q;
	for (int i=0;i<q;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		//cout<<x<<' '<<y<<' '<<w<<endl;
		trip[x][y]=trip[y][x]=w;
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		for (int u=1;u<=n;u++)
			tmp[u]=-LLINF;
		for (int u=1;u<=n;u++)
			for (int v=1;v<=n;v++)
				tmp[v]=max(tmp[v],trip[u][v]-g[u][i]);
		for (int j=1;j<=n;j++)
		{
			if (i==j || d[i][j]==LLINF)
				continue;
			//cout<<i<<' '<<j<<endl;
			for (int v=1;v<=n;v++)
			{
				//cout<<tmp[v]<<endl;
				if (d[i][j]+g[j][v]<=tmp[v])
				{
					cnt++;
					break;
				}
			}
		}
	}
	cout<<cnt/2<<endl;
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