#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 211000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL a[MAXN];
LL n,z;

int main()
{
	LL ans=0;
	cin>>n>>z;
	RPT(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	int ptr1=0,ptr2=n/2;
	while (ptr1<n/2 && ptr2<n)
		if (a[ptr2]-a[ptr1]>=z)
			ans++,ptr1++,ptr2++;
		else if (ptr2==n || ptr1==n/2)
			break;
		else
			ptr2++;
	cout<<ans;
	return ~~(0^_^0);
}