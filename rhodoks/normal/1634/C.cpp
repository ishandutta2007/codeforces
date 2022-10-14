#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,k;
int ans[510][510];
void init()
{

}

void work()
{
	cin>>n>>k;
	LL sum=(LL)(1+n*k)*(n*k)/2;
	if (sum%k)
	{
		cout<<"NO"<<endl;
		return ;
	}
	if (k>1 && n%2)
	{
		cout<<"NO"<<endl;
		return ;
	}

	cout<<"YES"<<endl;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<k;j++)
			cout<<i+j*n+1<<' ';
		putchar('\n');
	}
}

int main()
{
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}