#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL dp[MAXN]; 
LL sum[MAXN];
int a[MAXN];
LL n,d,m;
int main()
{
	cin>>n>>d>>m;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	LL ans=0;
	n--;
	LL p=lower_bound(a+1,a+n+1,m+1)-a;
	sort(a+1,a+p,greater<LL>());
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		//WRT(sum[i]); 
	}
	sum[n+1]=sum[n];
	for (int i=n;i>=p-1;i--)
	{
		if (n<(n-i)*(d+1))
			break;
		//WRT(i);
		//WRT(ans);
		//WRT(n+1-i)
		//WRT(sum[max(min(p-1,n-(n+1-i)*d),0ll)]);
		ans=max(ans,sum[n]-sum[i]+sum[max(min(p-1,n-(n-i)*(d+1)),0ll)]);
	}
	cout<<ans+a[n+1];
	return ~~(0^_^0);
}