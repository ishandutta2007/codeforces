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

typedef pair<int,int> pii;
vector<int> v;
int n,m;
int c[MAXN];
void work()
{
	v.clear();
	int x;
	scanf("%d%d",&n,&m);
	int maxv=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		maxv=max(maxv,x);
		v.push_back(x);
	}
	sort(v.begin(),v.end(),greater<int>());
	for (int i=1;i<=m;i++)
		scanf("%d",&c[i]);
	int ptr=1;
	LL ans=0;
	for (int i=0;i<n;i++)
	{
		if (ptr<v[i])
		{
			ans+=c[ptr++];
		}
		else
		{
			ans+=c[v[i]];
		}
	}
	printf("%lld\n",ans);
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