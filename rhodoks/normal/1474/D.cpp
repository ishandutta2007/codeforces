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
int a[MAXN]; 
int b[MAXN];

bool check()
{
	int tmp=a[1];
	for (int i=2;i<=n;i++)
	{
		tmp=a[i]-tmp;
		if (tmp<0)
			return false;
	}
	return tmp==0;
}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int res=0;
	res+=check();
	swap(a[1],a[2]);
	res+=check();
	swap(a[1],a[2]);
	swap(a[n-1],a[n]);
	res+=check();
	swap(a[n-1],a[n]);
	if (res)
	{
		printf("Yes\n");
		return;
	}
	b[n-1]=a[n];
	for (int i=n-2;i>=1;i--)
	{
		if (b[i+1]<0)
			b[i]=-INF;
		else
		{
			b[i]=a[i+1]-b[i+1];
			if (b[i]<0)
				b[i]=-INF;
		}
		//cout<<i<<' '<<b[i]<<endl;
	}
	int tmp=0;
	//WRT(a[0])
	for (int i=2;i<=n-1;i++)
	{
		swap(a[i-1],a[i]);
		//WRT( a[i]-(a[i-1]-tmp))
		if (tmp<=a[i-1] && a[i]-(a[i-1]-tmp)==b[i])
		{
			if (check()) 
			{
				printf("Yes\n");
				return;
			}
		}
		swap(a[i-1],a[i]);
		tmp=a[i-1]-tmp;
		//cout<<i<<' '<<tmp<<endl; 
	}
	printf("No\n");
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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