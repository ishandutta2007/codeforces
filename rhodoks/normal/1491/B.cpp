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

int n,u,v;
int a[MAXN];
void init()
{

}

void work()
{
	scanf("%d%d%d",&n,&u,&v);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool f1=false;
	for (int i=2;i<=n;i++)
	{
		if (abs(a[i]-a[i-1])>=2)
		{
			printf("%d\n",0);
			return;
		}
		if (abs(a[i]-a[i-1])==1)
		{
			f1=true;
		}
	}
	int ans=0;
	if (f1==false)
	{
		ans=min(u+v,v+v);
	}
	else
	{
		ans=min(u,v);
	}
	printf("%d\n",ans);
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