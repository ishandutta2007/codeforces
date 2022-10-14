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

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL a,b;
LL dp[MAXN];
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>a>>b;
		LL x=abs(a-b);
		if (x==0)
		{
			cout<<0<<endl;
			continue;
		}
		LL l=0,r=1e6;
		while (l!=r)
		{
			LL mid=(l+r)/2;
			if (mid*(mid+1)/2<x)
				l=mid+1;
			else
				r=mid;
		}
		LL y=r;
		for (;;y++)
		{
			//cout<<y*(y-1)/2<<' '<<x<<endl;
			if ((y*(y+1)/2-x)%2==0)
				break;
		}
		cout<<y<<endl;
	}
	return ~~(0^_^0);
}