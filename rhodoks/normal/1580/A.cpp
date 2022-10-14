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

char s[MAXN][MAXN];
int sum[MAXN][MAXN];
int ss[MAXN];
int n,m;
void init()
{

}

int query(int x1,int y1,int x2,int y2)
{
	//assert(x1>0 && y1>0);
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

//
void work()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>s[i]+1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			sum[i][j]=-sum[i-1][j-1]+sum[i-1][j]+sum[i][j-1]+s[i][j]-'0';
			//cout<<i<<' '<<j<<' '<<sum[i][j]<<endl;
		}
	//cout<<query(2,1,4,1)<<endl;
	//out<<query(2,5,4,5)<<endl;
	int ans=INF;
	for (int i=1;i<=n;i++)
		for (int j=i+4;j<=n;j++)
		{
			int mx=-INF;
			for (int x=1;x<=m;x++)
				ss[x]=query(i+1,1,j-1,x)-(query(i,1,i,x)+query(j,1,j,x))+2*x-(j-i-1-query(i+1,x,j-1,x));
			for (int r=4;r<=m;r++)
			{
				mx=max(mx,ss[r-3]);
				ans=min(ans,query(i+1,1,j-1,r-1)+2*(r-1)-query(i,1,i,r-1)-query(j,1,j,r-1)-mx+(j-i-1-query(i+1,r,j-1,r)));
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