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

int n;
int b[MAXN];
LL a[MAXN];
LL mx[MAXN];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		a[i]=b[i]+mx[i-1];
		printf("%lld ",a[i]);
		mx[i]=max(mx[i-1],a[i]);
	}
	
	return ~~(0^_^0);
}