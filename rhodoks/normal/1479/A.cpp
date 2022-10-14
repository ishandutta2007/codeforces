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

int n;
int query(int x)
{
	if (x==0 || x==n+1)
		return INF; 
	cout<<"? "<<x<<endl;
	int a;
	cin>>a;
	return a;
}
int a[MAXN];

void init()
{

}

void d(int l,int r)
{
	if (r==l)
	{
		cout<<"! "<<(l+r)/2<<endl;
		return ;
	}
	int mid=(l+r)/2;
	if (query(mid)<query(mid+1))
		d(l,mid);
	else
		d(mid+1,r);
}
void work()
{
	cin>>n;
	int l=1,r=n;
	d(l,r);
}

int main()
{
	#ifdef _DEBUG_
	//freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}