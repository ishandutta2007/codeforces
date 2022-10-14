#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,k;
int a[MAXN];

void op()
{
	int mx=-1000001000;
	for (int i=0;i<n;i++)
		mx=max(mx,a[i]);
	for (int i=0;i<n;i++)
		a[i]=mx-a[i];
}

void output()
{
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	
}

void work()
{
	cin>>n>>k;
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	k--;
	op();
	if (k&1)
		op();
	output();
}
int main()
{
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}