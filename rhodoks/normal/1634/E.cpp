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

vector<int> a[MAXN];
int n;
vector<pair<int,int*> > edge;
vector<int> g[MAXN];
int vis[MAXN];
int v[MAXN];
int cnt[MAXN];
int ptr[MAXN];
vector<int> euler;
void init()
{

}

void dfs(int pos)
{
	//cout<<pos<<endl;
	v[pos]=1;
	//for (auto p:g[pos])
	while (ptr[pos]<g[pos].size())
	{
		int p=g[pos][ptr[pos]++];
		if (vis[p])
			continue;
		vis[p]=1;
		vis[p^1]=1;
		dfs(edge[p].first);
		//cout<<p<<endl;
		*edge[p].second=(edge[p].first<=n);
	}
	//euler.push_back()
}
void work()
{
	vector<int> desc;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int k,x;
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d",&x);
			a[i].push_back(x);
			desc.push_back(x);
		}
	}
	sort(desc.begin(), desc.end());
	desc.resize(unique(desc.begin(), desc.end())-desc.begin());
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<a[i].size();j++)
		{
			a[i][j]=lower_bound(desc.begin(), desc.end(),a[i][j])-desc.begin()+1;
			cnt[a[i][j]]++;
			//WRT(a[i][j])
			g[i].push_back(edge.size());
			edge.push_back({a[i][j]+n,&a[i][j]});
			g[a[i][j]+n].push_back(edge.size());
			edge.push_back({i,&a[i][j]});
		}
	}
	for (int i=1;i<=desc.size();i++)
	{

		if (cnt[i]&1)
		{
			cout<<"NO"<<endl;
			return ;
		}
	}
	for (int i=1;i<=n+desc.size();i++)
		if (!v[i])
			dfs(i);
	//WRT()
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++)
	{
		for (auto p:a[i])
			if (p)
				putchar('L');
			else
				putchar('R');
		putchar('\n');
	}
}

int main()
{
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