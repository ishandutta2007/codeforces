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
 
int deg[MAXN],visit[MAXN];
typedef pair<int,int> pii;
int n,m,k,x,y;
set<pii> st;
vector<int> g[MAXN];
vector<vector<int> > clique;
unordered_set<int> gst[MAXN];
void work()
{
	scanf("%d%d%d",&n,&m,&k);
	st.clear();
	clique.clear();
	for (int i=1;i<=n;i++)
	{
		g[i].clear();
		deg[i]=visit[i]=0;
		gst[i].clear();
	}
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		gst[x].insert(y);
		gst[y].insert(x);
		deg[x]++;
		deg[y]++;
	}
	if ((LL)k*(k-1)>4ll*m)
	{
		printf("-1\n");
		return;
	}
	for (int i=1;i<=n;i++)
	{
		st.insert({deg[i],i});
	}
	while (st.size())
	{
		//WRT(st.size())
		int pos=st.begin()->second;
		//WRT(pos);
		int posdeg=deg[pos];
		//WRT(posdeg);
		visit[pos]=1;
		if (posdeg>=k)
		{
			printf("1 %d\n",st.size());
			for (auto p:st)
				printf("%d ",p.second);
			putchar('\n');
			return;
		}
		st.erase(st.begin());
		if (posdeg==k-1)
		{
			vector<int> tmp={pos};
			for (auto p:g[pos])
				if (!visit[p])
				{
					tmp.push_back(p);
				}
			//for (auto t:tmp)
			//	cout<<t<<' ';
			//cout<<" !"<<endl;
			clique.push_back(tmp);
		}
		deg[pos]=0;
		for (auto p:g[pos])
		{
			if (visit[p])
				continue;
			st.erase({deg[p],p});
			deg[p]--;
			if (deg[p])
				st.insert({deg[p],p});
		}
	}
	for (auto p:clique)
	{
		bool ok=1;
		for (int i=0;i<p.size();i++)
		{
			for (int j=i+1;j<p.size();j++)
			{
				if (gst[p[i]].find(p[j])==gst[p[i]].end())
				{
					ok=0;
					break;
				}
			}
			if (!ok)
				break;
		}
		if (ok)
		{
			printf("2\n");
			for (auto q:p)
				cout<<q<<' ';
			cout<<endl;
			return;
		}
	}
	cout<<-1<<endl;
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
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}