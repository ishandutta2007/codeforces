#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<x<<endl;

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
	int n,t;
	int x,y;
	cin>>n>>t;
	int ans=INF;
	int f=-1;
	RPT(i,1,n+1)
	{
		int tem;
		cin>>x>>y;
		if (x>=t)
			tem=x;
		else
		{
			tem=x+((t-x-1)/y+1)*y;
		}
		if (tem<ans)
		{
			ans=tem;
			f=i;
		}
	}
	cout<<f;

	return ~~(0^_^0);
}