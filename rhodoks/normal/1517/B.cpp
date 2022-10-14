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
int b[110][110];
int choose[110][110];
void init()
{

}

void work()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			choose[i][j]=0;
		
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>b[i][j];
	for (int j=1;j<=m;j++)
	{
		int x=1,y=1;
		for (int i=1;i<=n;i++)
			for (int k=1;k<=m;k++)
				if (b[x][y]>b[i][k])
					x=i,y=k;
		choose[x][j]=b[x][y];
		b[x][y]=INF;
		//cout<<x<<' '<<y<<endl;
	}
	/*
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<choose[i][j]<<' ';
		cout<<endl;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<b[i][j]<<' ';
		cout<<endl;
	}
	*/
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (choose[i][j])
				continue;
			for (int k=1;k<=m;k++)
				if (b[i][k]!=INF)
				{
					WRT(k);
					choose[i][j]=b[i][k];
					b[i][k]=INF;
					break;
				} 
		}
	} 
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<choose[i][j]<<' ';
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