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

int x,y;
int n[4],m[4];
int a[4][MAXN];
vector<int> g[4][MAXN];
int cost[4][MAXN];
typedef pair<int,int> pii;
multiset<int> st;
void init()
{

}

void work()
{
	for (int i=0;i<4;i++)
		cin>>n[i];
	for (int i=0;i<4;i++)
		for (int j=1;j<=n[i];j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<4;i++)
	{
		cin>>m[i];
		for (int j=0;j<m[i];j++)
		{
			scanf("%d%d",&x,&y);
			g[i][y].push_back(x);
		}
	}
	for (int i=1;i<4;i++)
	{
		st.clear();
		for (int j=1;j<=n[i-1];j++)
			st.insert(a[i-1][j]);
		for (int j=1;j<=n[i];j++)
		{
			for (auto p:g[i][j])
				st.erase(st.find(a[i-1][p]));
			if (st.size()==0)
				a[i][j]=INF;
			else
				a[i][j]=a[i][j]+(*st.begin());
			for (auto p:g[i][j])
				st.insert(a[i-1][p]);
		}
	}
	int ans=INF;
	for (int i=1;i<=n[3];i++)
		ans=min(ans,a[3][i]);
	if (ans>=INF)
		ans=-1;
	cout<<ans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
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