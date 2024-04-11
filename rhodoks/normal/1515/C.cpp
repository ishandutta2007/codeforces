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

int n,m,x;
int h[MAXN];
int id[MAXN];
int ans[MAXN];
bool cmp(int x,int y)
{
	return h[x]<h[y];
}
void init()
{

}

void work()
{
	cin>>n>>m>>x;
	for (int i=0;i<n;i++)
	{
		cin>>h[i];
		id[i]=i;
	}
	sort(id,id+n,cmp);
	cout<<"YES\n";
	for (int i=0;i<n;i++)
		ans[id[i]]=(i%m)+1;
	for (int i=0;i<n;i++)
		printf("%d ",ans[i]);
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