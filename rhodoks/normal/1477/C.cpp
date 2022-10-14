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

LL x[MAXN],y[MAXN]; 
bool visit[MAXN];
LL mx=0,mxp=0;
int n;
LL dis(int i,int j)
{
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&y[i]);
	int pos=1;
	cout<<1<<' ';
	visit[1]=1;
	for (int i=0;i<n-1;i++)
	{
		mxp=-1,mx=0;
		for (int j=1;j<=n;j++)
			if (!visit[j] && mx<dis(pos,j))
			{
				mx=dis(pos,j);
				mxp=j;
			}
		visit[mxp]=1;
		pos=mxp;
		cout<<mxp<<' ';
	}
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
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}