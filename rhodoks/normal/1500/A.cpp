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

#define MAXN 5010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int x[MAXN],y[MAXN];
int a[MAXN];
int n;
void init()
{

}

void work()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			if (x[a[i]+a[j]]==0)
			{
				x[a[i]+a[j]]=i;
				y[a[i]+a[j]]=j;
			}
			else if (y[a[i]+a[j]]!=j && y[a[i]+a[j]]!=i && x[a[i]+a[j]]!=j && x[a[i]+a[j]]!=i)
			{
				cout<<"YES"<<endl<<i<<' '<<j<<' '<<x[a[i]+a[j]]<<' '<<y[a[i]+a[j]]<<endl;
				return;
			}
		}
	cout<<"NO"<<endl;
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