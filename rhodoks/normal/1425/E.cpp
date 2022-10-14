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

int n,k;
LL d[MAXN],a[MAXN];
LL suma[MAXN]; 
LL tmp1[MAXN],tmp2[MAXN];
void work()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		suma[i]=suma[i-1]+a[i];
	}
	for (int i=1;i<=n;i++)
		scanf("%lld",&d[i]);
	LL ans=max(0ll,a[n]-d[n]);
	WRT(ans)
	if (k==0)
	{
		for (int i=1;i<=n;i++)
			ans=max(ans,suma[n]-suma[i-1]-d[i]);
	}
	if (k==1)
	{
		LL mi2=LLINF;
		for (int i=n-1;i>=1;i--)
		{
			mi2=min(mi2,a[i]);
			ans=max(ans,suma[n]-suma[i-1]-mi2-d[i]);
		}
		for (int i=n;i>=1;i--)
		{
			tmp1[i]=max(tmp1[i+1],suma[n]-suma[i-1]-d[i]);
		}
		LL mi=LLINF;
		for (int i=1;i<=n-1;i++)
		{
			mi=min(mi,d[i]);
			ans=max(ans,tmp1[i+1]+max(0ll,suma[i]-mi));
			//cout<<tmp1[i+1]<<' '<<suma[i]-mi<<endl;
		}
	}
	if (k>=2)
	{
		LL mi=LLINF;
		for (int i=1;i<=n-1;i++)
			mi=min(mi,d[i]);
		ans=max(ans,suma[n]-mi);
	}
	cout<<ans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}