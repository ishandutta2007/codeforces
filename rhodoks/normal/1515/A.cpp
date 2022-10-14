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

int n,x;
int a[MAXN];
int cnt[110];
void init()
{

}

bool check()
{
	int tmp=0;
	for (int i=0;i<n;i++)
	{
		tmp+=a[i];
		if (tmp==x)
			return false;
	}
	return true;
}

void shift()
{
	a[n]=a[0];
	for (int i=0;i<n;i++)
		a[i]=a[i+1];
}
void work()
{
	int sum=0;
	MST(cnt,0);
	cin>>n>>x;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		sum+=a[i];
	}
	for (int i=0;i<n;i++)
	{
		shift();
		if (check())
		{
			cout<<"YES\n";
			for (int i=0;i<n;i++)
				cout<<a[i]<<' ';
			cout<<endl;
			return;
		}
	}
	cout<<"NO\n";
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