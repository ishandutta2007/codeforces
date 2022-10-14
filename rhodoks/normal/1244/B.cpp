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

char s[11000];
int n;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		cin>>s;
		int l=-1,r=-1;
		for (int i=0;i<n;i++)
			if (s[i]=='1')
			{
				l=i;
				break;
			}
		for (int i=n-1;i;i--)
			if (s[i]=='1')
			{
				r=i;
				break;
			}
		if (l==-1)
		{
			cout<<n<<endl;
			continue;
		}
		cout<<2*n-2*min(l,n-r-1)<<endl;
	}
	return ~~(0^_^0);
}