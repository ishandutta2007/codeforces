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

#define MAXN 605000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char str[MAXN];
int n;

int main()
{
	cin>>n;
	cin>>str;
	RPT(i,0,n-1)
		if (str[i]>str[i+1])
		{
			cout<<"YES"<<endl;
			cout<<i+1<<' '<<i+2<<endl;
			return 0;
		}
	cout<<"NO";
		
	return ~~(0^_^0);
}