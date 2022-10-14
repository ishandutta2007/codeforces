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

int main()
{
	char c[10]={"aeiou"};
	int k;
	cin>>k;
	int n,m;
	RPT(i,5,sqrt(k)+1)
	{
		if (k%i!=0)
			continue;
		n=i;
		m=k/i;
		if (m<5)
			break;
		RPT(i,0,n)
		{
			RPT(j,0,m)
				cout<<c[(i+j)%5];
		}
		return 0;
	}
	cout<<-1;
	return ~~(0^_^0);
}