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

LL n,p;
LL sum=0;

LL countbit(LL x)
{
	int ans=0;
	for (LL i=0;i<60;i++)
		if (x & ((LL)1<<i))
			ans++;
	return ans;
}

int main()
{
	cin>>n>>p;
	if (n<1+p)
	{
		cout<<-1;
		return 0;
	}
	for (LL i=1;i<=1000;i++)
	{
		LL pos=n-i*p;
		if (pos<=0)
			break;
		if (countbit(n-i*p)<=i && n-i*p>=i)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return ~~(0^_^0);
}