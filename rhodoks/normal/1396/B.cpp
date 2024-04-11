#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL sum,mx,n,x;
 
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		sum=0;
		mx=0;
		cin>>n;
		while (n--)
		{
			cin>>x;
			sum+=x;
			mx=max(mx,x);
		}
		if (mx*2>sum)
			cout<<"T";
		else if (sum&1)
			cout<<"T";
		else
			cout<<"HL";
		putchar('\n');
	}
	return ~~(0^_^0);
}