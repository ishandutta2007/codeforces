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
int n,h;
LL xh,yh,xm,ym; 
DB ans=0;

LL cross(LL x1,LL y1,LL x2,LL y2)
{
	return x1*y2-x2*y1;	
}

void work()
{
	cin>>n>>h;
	for (int i=1;i<=n;i++)
		scanf("%lld%lld",x+i,y+i);
	xh=x[n];
	yh=y[n]+h;
	xm=x[n];
	ym=y[n];
	for (int i=n-1;i>=1;i--)
	{
		if (cross(x[i]-xh,y[i]-yh,xm-x[i],ym-y[i])>=0)
		{
			LL d1=abs((yh-ym)*x[i]-(xh-xm)*y[i]+xh*ym-xm*yh);
			LL d2=abs((yh-ym)*x[i+1]-(xh-xm)*y[i+1]+xh*ym-xm*yh);
			//cout<<i<<' '<<d1<<' '<<d2<<endl;
			if (d1+d2)
				ans+=sqrt((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]))
						*d1/(d1+d2);
			else
				ans+=sqrt((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]));
			//WRT(ans) 
			xm=x[i];
			ym=y[i];
		}
	}
	printf("%.10lf\n",ans); 
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