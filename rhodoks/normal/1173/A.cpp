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

LL a,b,c;

int main()
{
	cin>>a>>b>>c;
	LL l=a-b-c;
	LL r=a-b+c;
	if (l>0)
		cout<<"+";
	else if (r<0)
		cout<<"-";
	else if (l==0 && r==0)
		cout<<0;
	else cout<<"?";
	return ~~(0^_^0);
}