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


LL gcd(LL x,LL y)
{
	if (x<y)
		swap(x,y); 
	if (y==0)
		return x;
	return gcd(y,x%y);
}

LL a[MAXN];
int n;
LL k;

void work()
{
	scanf("%d%lld",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)
		if (a[i]==k)
		{
			printf("YES\n");
			return;
		}
	LL gc=0;
	for (int i=1;i<=n-1;i++)
		gc=gcd(gc,abs(a[i]-a[i+1]));
	if (gc)
	{
		WRT(gc)
		for (int i=1;i<=n;i++)
			if ((k-a[i])%(2ll*gc)==0)
			{
				printf("YES\n");
				return;
			}
	}
	printf("NO\n");
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
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}