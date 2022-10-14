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

#define int LL
int a[MAXN],b[MAXN];
LL ans=LLINF;
LL sum=0;
LL c;
LL tmp;
int n;

void init()
{

}

void work()
{
	ans=LLINF;
	tmp=-1;
	sum=0;
	cin>>n>>c;
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=2;i<=n;i++)
		scanf("%lld",&b[i]);
	for (int i=1;i<=n;i++)
	{
		if (b[i]>sum)
		{
			tmp+=((b[i]-sum-1)/a[i-1]+1);
			sum+=((LL)(b[i]-sum-1)/a[i-1]+1)*a[i-1];
		}
		tmp++;
		sum-=b[i];
		if (sum>=c)
			break;
		//WRT(tmp)
		ans=min(ans,tmp+(c-sum-1)/a[i]+1);
	}
	cout<<ans<<endl; 
}

signed main()
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