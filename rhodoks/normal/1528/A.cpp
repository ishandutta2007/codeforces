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

vector<int> g[MAXN];

int l[MAXN],r[MAXN];
LL dp[MAXN][2];
int n;
void init()
{

}

void dfs(int pos,int f)
{
	for (auto p:g[pos])
		if (p!=f)
		{
			dfs(p,pos);
			dp[pos][0]=max(dp[pos][0]+dp[p][0]+abs(l[pos]-l[p]),dp[pos][0]+dp[p][1]+abs(l[pos]-r[p]));
			dp[pos][1]=max(dp[pos][1]+dp[p][0]+abs(r[pos]-l[p]),dp[pos][1]+dp[p][1]+abs(r[pos]-r[p]));
		}
}


void work()
{
	int x,y;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		dp[i][0]=dp[i][1]=0;
		g[i].clear();
		scanf("%d%d",&l[i],&r[i]);
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,1);
	cout<<max(dp[1][1],dp[1][0])<<endl;
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