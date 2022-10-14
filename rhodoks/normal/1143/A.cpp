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

int q[200100];
int a[2];
int n;
int main()
{
	cin>>n;
	RPT(i,1,n+1)
	{
		scanf("%d",&q[i]);
		a[q[i]]++;
	}
	RPT(i,1,n+1)
	{
		a[q[i]]--;
		if (a[q[i]]==0)
		{
			cout<<i;
			return 0;
		}
	}
	return ~~(0^_^0);
}