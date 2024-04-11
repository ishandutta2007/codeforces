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


int n,k;
int a[MAXN];

void work()
{
	cin>>n;
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	LL ans=0;
	for (int i=1;i<n;i++)
		if (a[i]<a[i-1])
			ans+=a[i-1]-a[i];
	printf("%lld\n",ans);
}
int main()
{
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}