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
int n,m;
LL tp,x,y;
int ans[MAXN];
int s=0;
int flag[MAXN];

int dfs(int pos,int dep)
{
	flag[pos]=s;
	int d=INF;
	if (ans[pos])
		d=dep;
	
	for (auto p:g[pos])
	{
		d=min(d,dfs(p,dep+1));
	}
	if (d-dep<=y)
	{
		if (ans[pos]==0)
		{
		WRT(pos)
		WRT(s)
			ans[pos]=s;
		}
	}
	return d;
}

void init()
{

}

void work()
{
	cin>>n>>m;
		ans[0]=1;
	for (s=2;s<=n+1;s++)
	{
		cin>>tp>>x>>y;
		for (int i=0;i<=m;i++)
			g[i].clear();
		if (tp==1)
		{
				WRT((x-1)/100000+1)
			for (int i=0;i<=m;i++)
			{
				if (i+(x-1)/100000+1<=m)
					g[i+(x-1)/100000+1].push_back(i);
			}
		}
		else
		{
			for (int i=1;i<=m;i++)
			{
				if (((LL)i*x-1)/100000+1<=m)
					g[((LL)i*x-1)/100000+1].push_back(i);
			}
		}
		for (int i=m;i>=0;i--)
		{
			if (ans[i] || flag[i]==s)
				continue;
			dfs(i,1);
		}
	}
	for (int i=1;i<=m;i++)
		cout<<ans[i]-1<<' ';
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