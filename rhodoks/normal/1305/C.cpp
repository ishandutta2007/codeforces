#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL a[MAXN];
int n,m;
LL ans=1;
LL cnt[MAXN];
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cnt[a[i]%m]++;
		if (cnt[a[i]%m]>=2)
		{
			cout<<0;
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			ans=ans*abs(a[i]-a[j])%m;
	cout<<ans;
	return ~~(0^_^0);
}