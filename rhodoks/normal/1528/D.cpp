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

int n,m;

LL dis[610];
int visit[MAXN];
int g[610][610];

int getdis(int x,int y,int t)
{
	return g[x][((y-t)%n+n)%n];
}

 
void dijkstra(int s)
{
	for (int i=0;i<=n;i++)
	{
		dis[i]=LLINF;
		visit[i]=0;
	}
	dis[n]=LLINF+1;
	dis[s]=0;
	for (int i=1;i<=n;i++)
	{
		int pos=n;
		for (int j=0;j<n;j++)
			if (dis[j]<dis[pos] && visit[j]==0)
				pos=j;
		visit[pos]=1;
		for (int j=0;j<n;j++)
		{
			if (visit[j]==0)
			{
				//WRT(pos)
				dis[j]=min(dis[j],dis[pos]+getdis(pos,j,dis[pos]));
			}
		}
	}
	for (int i=0;i<n;i++)
		cout<<dis[i]<<' ';
	cout<<endl;
}

void init()
{

}

void work()
{
	MST(dis,INF);
	MST(g,INF);
	cin>>n>>m;
	int a,b,c;
	for (int i=0;i<m;i++)
	{
		int cnt=0;
		cin>>a>>b>>c;
		g[a][b]=min(g[a][b],c);
		int pos=b+1;
		if (pos>=n)
			pos-=n;
		cnt++;
		c++;
		while (pos!=b)
		{
			g[a][pos]=min(g[a][pos],c);
			pos++;
			if (pos>=n)
				pos-=n;
			cnt++;
			c++;
		}
	}
	//for (int i=0;i<n;i++)
	//	g[i][i]=0;
	
	for (int i=0;i<n;i++)
		dijkstra(i);
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