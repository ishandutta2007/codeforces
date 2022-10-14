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

int a[MAXN],b[MAXN];
int n,m;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		for (int i=0;i<n;i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for (int i=0;i<n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
		for (int i=0;i<n;i++)
			cout<<b[i]<<' ';
		cout<<endl;
	}
	return ~~(0^_^0);
}