#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<x<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int h[1100][1100];
int n,m,H;
int x[1000],y[1000];
int main()
{
	cin>>n>>m>>H;
	RPT(i,1,m+1)
		scanf("%d",&x[i]);
	RPT(i,1,n+1)
		scanf("%d",&y[i]);
	RPT(i,1,n+1)
		RPT(j,1,m+1)
		{
			scanf("%d",&h[i][j]);
		}
	RPT(i,1,m+1)
	{
		if (x[i]==0)
			continue;
		int tem=-1;
		RPT(j,1,n+1)
		{
			if (y[j]>=x[i] && h[j][i]!=0)
				tem=j;
		}
		h[tem][i]=x[i];
	}
	RPT(i,1,n+1)
	{
		if (y[i]==0)
			continue;
		int tem=-1;
		RPT(j,1,m+1)
		{
			if (y[i]<=x[j] && h[i][j]!=0)
				tem=j;
		}
		h[i][tem]=y[i];
	}
	RPT(i,1,n+1)
	{
		RPT(j,1,m+1)
			printf("%d ",h[i][j]);
		printf("\n");
	}
	return ~~(0^_^0);
}