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

void init()
{

}

void work()
{
	int n;
	cin>>n;
	if (n<26)
	{
		for (int c='a';c<'a'+n;c++)
			putchar(c);
		cout<<endl;
		return ;
	}
	for (int i=0;i<n/2;i++)
		putchar('a');
	if (n&1)
		cout<<"bc";
	else
		cout<<'b';
	for (int i=0;i<n/2-1;i++)
		putchar('a');
	putchar('\n');
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	cin>>casenum;
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		work();
	}
	return ~~(0^_^0);
}