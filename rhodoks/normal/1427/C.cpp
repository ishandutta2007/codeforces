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

int r,n;
int t[MAXN],x[MAXN],y[MAXN],ans[MAXN];

void work()
{
	cin>>r>>n;
	x[0]=y[0]=1;
	int res=0;
	int mx=-INF;
	for (int i=1;i<=n;i++)
	{
		ans[i]=-INF;
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
		for (int j=i-1;j>=max(0,i-1010);j--)
			if (abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
			{
				//cout<<i<<' '<<j<<endl;
				ans[i]=max(ans[i],ans[j]+1);
			}
		ans[i]=max(ans[i],mx+1);
		if (i>=1005)
			mx=max(mx,ans[i-1005]);
		//WRT(ans[i])
		res=max(res,ans[i]);
	}
	cout<<res<<endl;
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