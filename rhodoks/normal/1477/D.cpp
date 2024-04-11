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
int ansp[MAXN],ansq[MAXN]; 
int n,m,x,y,cnt,treecnt;
int deg[MAXN];
vector<int> tree[MAXN];
typedef pair<int,int> pii;
int center[MAXN];
set<int> star[MAXN];
set<pii,greater<pii> > st;
set<int> rev; 
void dfs1(int pos)
{
	int ptr=0;
	rev.erase(pos);
	int p=0;
	while (1)
	{
		auto it=rev.lower_bound(p);
		if (it==rev.end())
			return;
		p=*it;
		auto vit=lower_bound(g[pos].begin(),g[pos].end(),p);
		if (vit!=g[pos].end() && *vit==p)
		{
			p++;
			continue;
		}
		tree[pos].push_back(p);
		tree[p].push_back(pos);
		//cout<<p<<' '<<pos<<endl;
		treecnt++;
		dfs1(p);
	}
}
 
 
void work()
{
	cin>>n>>m;
	st.clear();
	cnt=0;
	treecnt=1;
	for (int i=1;i<=n;i++)
	{
		ansp[i]=ansq[i]=deg[i]=center[i]=0;
		g[i].clear();
		tree[i].clear();
		star[i].clear();
	}
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		//cout<<x<<' '<<y<<endl;
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++,deg[y]++;
	}
	for (int i=1;i<=n;i++)
		sort(g[i].begin(),g[i].end());
	for (int i=1;i<=n;i++)
	{
		st.insert({deg[i],i});
		//WRT(st.begin()->second);
	}
	cnt=n;
	while (st.begin()->first==cnt-1)
	{
		//for (int i=1;i<=n;i++)
		//	cout<<i<<' '<<deg[i]<<'!'<<endl;
		int pos=st.begin()->second;
		WRT(pos);
		st.erase({deg[pos],pos});
		ansp[pos]=ansq[pos]=cnt;
		cnt--;
		for (auto p:g[pos])
		{
			if (ansp[p])
				continue;
			st.erase({deg[p],p});
			deg[p]--;
			st.insert({deg[p],p});
		}
	}
	WRT(cnt)
	for (int i=1;i<=n;i++)
		if (ansp[i]==0)
			rev.insert(i); 
	for (int i=1;i<=n;i++)
	{
		WRT(i)
		WRT(rev.count(i))
		if (rev.count(i))
		{
			WRT(i);
			dfs1(i);
			//break;
		}
	}
	WRT(treecnt)
	for (int i=1;i<=n;i++)
		if (deg[i]<cnt-1)
		{
			if (center[i]==0)
			{
				WRT(i)
				for (auto p:tree[i])
					if (center[p]==p)
					{
						center[i]=p;
						star[p].insert(i);
						break;
					}
				WRT(i)
				if (center[i])
					continue; 
				center[i]=i;
				for (auto p:tree[i])
					if (center[p]==0)
					{
						center[p]=i;
						star[i].insert(p);
					}
				if (star[i].size()==0)
				{
					int to=tree[i][0];
					if (star[center[to]].size()>=2)
					{
						star[center[to]].erase(to);
						star[i].insert(to);
						center[to]=i;
					}
					else
					{
						WRT(to)
						WRT(i)
						WRT(center[to])
						star[center[to]].erase(to);
						star[to].insert(center[to]);
						star[to].insert(i);
						center[center[to]]=center[i]=to;
						center[to]=to;
						MRK();
					}
						
				}
			}
		}
	MRK();
	int tmp=1;
	for (int i=1;i<=n;i++)
		if (star[i].size())
		{
			WRT(i);
			for (auto p:star[i])
				WRT(p);
			ansp[i]=tmp;
			ansq[i]=tmp+star[i].size();
			tmp++;
			for (auto p:star[i])
			{
				ansp[p]=tmp;
				ansq[p]=tmp-1;
				tmp++;
			}
		}
	for (int i=1;i<=n;i++)
		printf("%d ",ansp[i]);
	putchar('\n');
	for (int i=1;i<=n;i++)
		printf("%d ",ansq[i]);
	putchar('\n');
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