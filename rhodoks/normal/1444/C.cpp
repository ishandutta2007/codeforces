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

int n,m,k;
int col[MAXN];
vector<int> g[MAXN];
vector<int> G[MAXN];
int component[MAXN];
int visit[MAXN];
int c=0;
bool valid[MAXN];
int depth[MAXN];
vector<pii> edge;
LL ans=0;

bool cmp(pii p1,pii p2)
{
	if (col[p1.first]==col[p2.first])
		return col[p1.second]<col[p2.second];
	return col[p1.first]<col[p2.first];
}

void dfs(int pos,int c)
{
	component[pos]=c;
	for (auto p:g[pos])
	{
		if (col[p]==col[pos])
		{
			if (component[p]==0)
			{
				depth[p]=depth[pos]^1;
				dfs(p,c);
			}
			else
			{
				if (depth[pos]==depth[p])
					valid[col[pos]]=0;
			}
		}
	}
}

void init()
{
	int x,y;
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++)
		valid[i]=1;
	for (int i=1;i<=n;i++)
		scanf("%d",&col[i]);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		//cout<<x<<' '<<y<<endl;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		if (component[i]==0)
		{
			dfs(i,++c); 
		}
	edge.push_back({0,0});
	for (int i=1;i<=n;i++)
		for (auto p:g[i])
		{
			if (col[i]<col[p] &&  valid[col[i]] && valid[col[p]])
			{
				//cout<<i<<' '<<p<<endl;
				edge.push_back({i,p});
			}
		}
	sort(edge.begin()+1,edge.end(),cmp);
	edge.push_back({0,0});
}

vector<int> tmp;

bool fxxk(int pos)
{
	WRT(pos)
	WRT(visit[pos])
	for (auto p:G[pos])
	{
		//cout<<pos<<' '<<p<<endl;
		if (visit[p]==1)
		{
			visit[p]=visit[pos]^1;
			if (!fxxk(p))
				return false;
		}
		if (visit[p]>=2)
			if (visit[pos]==visit[p])
				return false;
	}
	return true;
}

bool check(vector<int> tmp)
{
	MRK(); 
	bool flag=true;
	for (auto p:tmp)
		visit[p]=1;
	for (auto p:tmp)
		if (visit[p]==1)
		{
			visit[p]=2;
			if (!fxxk(p))
			{
				flag=false;
				break;
			}
		}
	for (auto p:tmp)
	{
		visit[p]=0;
		G[p].clear();
	}
	return flag;
}

void work()
{
	int cnt=n;
	for (int i=1;i<edge.size();i++)
	{
		int x=edge[i].first;
		int y=edge[i].second;
		//cout<<x<<' '<<y<<' '<<col[x]<<' '<<col[y]<<endl;

		if (col[edge[i-1].first]!=col[x] || col[edge[i-1].second]!=col[y])
		{
			if (!check(tmp))
				ans--;
			tmp.clear();
			cnt=n;
		}
		int cx=component[x];
		int cy=component[y];
		tmp.push_back(cx);
		tmp.push_back(cy);
		if (depth[x]!=depth[y])
		{
			G[cx].push_back(cy);
			G[cy].push_back(cx);
			//cout<<cx<<'-'<<cy<<endl;
		}
		else
		{
			++cnt;
			G[cx].push_back(cnt);
			G[cnt].push_back(cx);
			G[cy].push_back(cnt);
			G[cnt].push_back(cy);
			//cout<<cx<<'-'<<cnt<<endl;
			//cout<<cnt<<'-'<<cy<<endl;
			tmp.push_back(cnt);
		}
		WRT(tmp.size())
	}
	WRT(ans)
	int sum=0;
	WRT(k) 
	for (int i=1;i<=k;i++)
		if (valid[i])
			sum++;
	WRT(sum)
	cout<<(LL)sum*(sum-1)/2+ans<<endl;
}


int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	work();
	return ~~(0^_^0);
}