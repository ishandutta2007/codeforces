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

char s[MAXN];
LL dp[MAXN];
int p,n,k,x,y;

void work()
{
	cin>>n>>p>>k>>s>>x>>y;
	p--;
	for (int i=n-1;i>=0;i--)
	{
		if (i+k>=n)
		{
			if (s[i]=='1')
				dp[i]=0;
			else
				dp[i]=x;
		}
		else
		{
			if (s[i]=='1')
				dp[i]=dp[i+k];
			else
				dp[i]=dp[i+k]+x;
		}
		//cout<<i<<' '<<dp[i]<<endl;
	}
	LL ans=LLINF;
	for (int i=p;i<n;i++)
		ans=min(ans,(LL)(i-p)*y+dp[i]);
	cout<<ans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}