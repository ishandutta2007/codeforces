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
int visit[MAXN]; 
int n,m,x,y;
int cnt=0;

int bfs(int pos)
{
	cnt=0;
	queue<int> q;
	q.push(pos);
	visit[pos]=2;
	cnt++;
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		for (auto p:g[pos])
			if (!visit[p])
			{
				q.push(p);
				visit[p]=2;
				cnt++;
			}
	}
	return cnt;
}


bool bfs1(int pos)
{
	cnt=0;
	queue<int> q;
	q.push(pos);
	visit[pos]=2;
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		for (auto p:g[pos])
		{
			if ((visit[p]&2))
				continue;
			if ((visit[p]&1)==0)
				for (auto q:g[p])
					visit[q]|=1;
			q.push(p);
			visit[p]|=2;
		}
	}
	return true;
}

void work()
{
	cnt=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		visit[i]=0;
		g[i].clear();
	}
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	if (bfs(1)!=n)
	{
		printf("NO\n");
		return;
	}
	
	vector<int> ans;
	for (int i=1;i<=n;i++)
		visit[i]=0;
	if (bfs1(g[1][0])) 
	{
		printf("YES\n");
		for (int i=1;i<=n;i++)
			if (visit[i]==2)
				ans.push_back(i);
		printf("%d\n",ans.size());
		for (auto p:ans)
			printf("%d ",p);
		putchar('\n');
		return;
	}
	for (int i=0;i<1000;i++)
	{
		int pos=(rand()*rand())%n+1;
		for (int i=1;i<=n;i++)
			visit[i]=0;
		if (bfs1(pos)) 
		{
			printf("YES\n");
			for (int i=1;i<=n;i++)
				if (visit[i]==2)
					ans.push_back(i);
			printf("%d\n",ans.size());
			for (auto p:ans)
				printf("%d ",p);
			putchar('\n');
			return;
		}
	}
	printf("NO\n");
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