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

int a[MAXN];
int n;
void init()
{

}

void work()
{
	LL ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=a[n+1]=0;
	for (int i=1;i<=n+1;i++)
		ans+=abs(a[i]-a[i-1]);
		//WRT(a[i]-max(a[i-1],a[i+1]));
	for (int i=1;i<=n;i++)
	{
		if (a[i]>a[i-1] && a[i]>a[i+1])
		{
			ans-=a[i]-max(a[i-1],a[i+1]);
			a[i]=max(a[i-1],a[i+1]);
		}
	}
	printf("%lld\n",ans);
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