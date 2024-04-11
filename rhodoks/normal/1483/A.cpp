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

int n,m;
vector<int> g[MAXN];
int k,x;
int ptr[MAXN];
int cnt[MAXN];
void init()
{

}

void work()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cnt[i]=0;
	//MRK();
	for (int i=1;i<=m;i++)
	{
		g[i].clear();
		ptr[i]=0;
		scanf("%d",&k);
		//WRT(k);
		for (int j=0;j<k;j++)
		{
			scanf("%d",&x);
			g[i].push_back(x);
		}
		cnt[g[i][0]]++;
	}
	for (int i=1;i<=m;i++)
		if (cnt[g[i][0]]>(m+1)/2 && g[i].size()>1)
		{
			cnt[g[i][0]]--;
			cnt[g[i][1]]++;
			ptr[i]=1;
		}
	//MRK();
	int mx=0;
	for (int i=1;i<=n;i++)
		mx=max(mx,cnt[i]);
	if (mx>(m+1)/2)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for (int i=1;i<=m;i++)
			printf("%d ",g[i][ptr[i]]);
		putchar('\n');
	}
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