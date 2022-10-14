#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

#define int LL
LL a[MAXN];
LL sum=0;
int n;
signed main()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if (n&1)
	{
		int p=sum%n;
		int s=sum/n;
		if (p==0)
		{
			for (int i=s-n/2;i<=s+n/2;i++)
				printf("%lld ",i);
			return 0;
		}
		for (int i=s-n/2+1;i<=s-n/2+p;i++)
			printf("%lld ",i);
		for (int i=s-n/2+p;i<=s+n/2;i++)
			printf("%lld ",i);
	}
	else
	{
		
		int p=(sum+n/2)%n;
		int s=(sum+n/2)/n-1;
		//WRT(p);
		//WRT(s);
		if (p==0)
		{
			for (int i=s-n/2+1;i<=s+n/2;i++)
				printf("%lld ",i);
			return 0;
		}
		for (int i=s-n/2+2;i<=s-n/2+p+1;i++)
			printf("%lld ",i);
		for (int i=s-n/2+p+1;i<=s+n/2;i++)
			printf("%lld ",i);
	}
	return ~~(0^_^0);
}