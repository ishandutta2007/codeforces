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
char s[510][510];
int sum[510][510];
void work()
{
	cin>>n>>m;
	int ans=0;
	for (int i=1;i<=n;i+=1)
	{
		cin>>s[i]+1;
		for (int j=1;j<=m;j++)
			sum[i][j]=sum[i][j-1]+(s[i][j]=='*');
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			for (int k=0;k<m;k++)
			{
				if (i+k>n || j-k<=0 || j+k>m)
					break;
				bool f=true;
				if (sum[i+k][j+k]-sum[i+k][j-k-1]!=2*k+1)
					break;
				ans++;
			}
		}
	cout<<ans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}