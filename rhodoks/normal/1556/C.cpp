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
int n;
int c[MAXN];
LL l[MAXN],r[MAXN];
void init()
{

}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>c[i];
	r[0]=0;
	for (int i=1;i<=n;i++)
	{
		l[i]=r[i-1];
		if (i%2)
		{
			r[i]=l[i]+c[i]-1;
		}
		else
		{
			//l[i]--;
			r[i]=l[i]-c[i]+1;
		}
		//if (i==1)
		//	r[i]++;
		//cout<<l[i]<<' '<<r[i]<<endl;
	}
	LL ans=0;
	for (int i=1;i<=n;i+=2)
	{
		LL mi=LLINF;
		for (int j=i+1;j<=n;j+=2)
		{
			mi=min(l[j],mi);
			LL tmp=min(min(r[i],l[j]),mi)-max(l[i],r[j]);
			//cout<<i<<' '<<j<<endl<<l[i]<<' '<<r[i]<<' '<<l[j]<<' '<<r[j]<<' '<<mi<<' '<<tmp<<endl;
			if (tmp>=0)
				ans+=tmp+1;
			mi=min(r[j],mi);
		}
	}
	cout<<ans<<endl;
}

signed main()
{
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