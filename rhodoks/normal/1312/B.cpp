#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int t;
int a[MAXN];

int main()
{
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for (int i=n-1;i>=0;i--)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return ~~(0^_^0);
}