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

LL k,l,r,t,x,y; 
int buc[MAXN*2];
void work()
{
	cin>>k>>l>>r>>t>>x>>y;
	if (x==y)
	{
		if (k-x>=l || k+x<=r)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		return;
	}
	if (x>y)
	{
		if (k-(x-y)*(t-1)-x>=l && (DB)k-(DB)(x-y)*(t-1)-(DB)x>=(DB)l)
		{
			cout<<"Yes"<<endl;
			return;
		} 
		if (k+y<=r && k-(x-y)*t>=l && (DB)k-(DB)(x-y)*t>=(DB)l)
		{
			cout<<"Yes"<<endl;
			return;
		} 
		cout<<"No"<<endl;
		return;
	}
	LL sumt=0;
	while (sumt<t)
	{
		if (buc[(k-l)%x])
			break;
		buc[(k-l)%x]=1;
		sumt+=(k-l)/x;
		k-=(k-l)/x*x;
		if (k+y>r && sumt<t)
		{
			cout<<"No"<<endl;
			return;
		}
		k+=y;
	}
	cout<<"Yes"<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}