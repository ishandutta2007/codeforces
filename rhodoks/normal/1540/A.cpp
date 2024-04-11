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

int d[MAXN];
int n;
int mx=0;
void init()
{
}

void work()
{
	mx=0;
	cin>>n;
	//WRT(n); 
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]); 
		mx=max(mx,d[i]);
	}
	sort(d+1,d+n+1);
	LL ans=0;
	LL tmp=0;
	for (LL i=1;i<=n;i++)
	{
		tmp+=d[i];
		ans+=tmp-i*d[i];
	}
	ans+=mx;
	cout<<ans<<endl;

}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	scanf("%d",&casenum);
	//WRT(casenum); 
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}