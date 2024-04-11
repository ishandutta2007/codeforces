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

bool cmp(int x,int y)
{
	return abs(x)<abs(y);
}

double dis(int x,int y)
{
	return sqrt((LL)x*x+(LL)y*y);
}
void work()
{
	vector<int> vx,vy;
	int n,x,y;
	cin>>n;
	for (int i=0;i<2*n;i++)
	{
		scanf("%d%d",&x,&y);
		if (x==0)
			vy.push_back(y);
		else
			vx.push_back(x);
	}
	sort(vx.begin(),vx.end(),cmp);
	sort(vy.begin(),vy.end(),cmp);
	double ans=0;
	for (int i=0;i<n;i++)
		ans+=dis(vx[i],vy[i]);
	printf("%.10lf\n",ans);
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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