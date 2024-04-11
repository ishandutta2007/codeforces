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

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN];
int used[MAXN];

int main()
{
	int n;
	cin>>n;
	int cur=n;
	n--;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cout<<a[1]<<endl;
	used[a[1]]=1;
	for (int i=1;i<=n;i++)
	{
		while (used[cur])
			cur--;
		if (used[a[i+1]] || i==n)
		{
			cout<<a[i]<<' '<<cur<<endl;
			used[cur]=1;
		}
		else
		{
			cout<<a[i]<<' '<<a[i+1]<<endl;
			used[a[i+1]]=1;
		}
	}
	return ~~(0^_^0);
}