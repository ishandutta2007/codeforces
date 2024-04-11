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

int a[MAXN];
void work()
{
	LL n,k;
	cin>>n>>k;
	for (int i=0;i<=n;i++)
		a[i]=i;
	k--;
	//WRT(k);
	if (n<=62 && (1ll<<(n-1))<=k)
	{
		cout<<-1<<endl;
		return ;
	}
	int cnt=0;
	for (LL j=62;j>=0;j--)
	{
		if (k>=(1ll<<j))
		{
			///WRT(j);
			//WRT(cnt)
			k-=(1ll<<j);
			cnt++;
		}
		else
		{
			//WRT(cnt);
			/*
			if (cnt)
			{
				WRT(j)
				WRT(cnt);
			}
			*/
			reverse(a+n-j-cnt-1,a+n-j);
			cnt=0;
		}
	}
	reverse(a+n-cnt,a+n+1);
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
	putchar('\n');
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