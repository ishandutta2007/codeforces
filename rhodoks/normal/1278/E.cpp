#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 510000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int cur=1;
vector<int> g[MAXN];
int bg[MAXN];
int ed[MAXN];
int n;

void dfs(int pos,int pa)
{
	cur+=g[pos].size()-(pos!=1);
	int tmp=cur;
	ed[pos]=++cur;
	for (auto p:g[pos])
		if (p!=pa)
		{
			bg[p]=tmp--;
			dfs(p,pos);
		}
}

int main()
{
	int x,y;
	cin>>n;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bg[1]=1;
	dfs(1,1);
	for (int i=1;i<=n;i++)
		printf("%d %d\n",bg[i],ed[i]); 
	return ~~(0^_^0);
}