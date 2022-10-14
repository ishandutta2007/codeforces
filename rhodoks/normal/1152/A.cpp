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

LL a[10][10];

int main()
{
	int x;
	int n,m;
	cin>>n>>m;
	RPT(i,0,n)
	{
		scanf("%d",&x);
		a[0][x%2]++;
	}
	RPT(i,0,m)
	{
		scanf("%d",&x);
		a[1][x%2]++;
	}
	cout<<min(a[0][0],a[1][1])+min(a[0][1],a[1][0]);
	return ~~(0^_^0);
}