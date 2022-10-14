#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL a[MAXN],p[MAXN];

void insert(LL x)
{
	for (int j=62;j>=0;j--)
		if ((x>>j)&1)
		{
			if (p[j])
				x^=p[j];
			else
			{
				p[j]=x;
				break;
			}
		}
}

LL getans(LL ans)
{
	for (int i=62;i>=0;i--)
	{
		if (((ans>>i)&1)==0)
			continue;
		else
			if (p[i])
				ans^=p[i];
	}
	return ans;
}

typedef pair<int,LL> pil;
vector<pil> g[MAXN];
int n,m,s,t;
LL d;
bool visit[MAXN];
int depth[MAXN];
LL v[MAXN];

void dfs(int pos,int f,LL val)
{
	depth[pos]=depth[f]+1;
	visit[pos]=1;
	v[pos]=val;
	for (auto p:g[pos])
		if (p.first!=f)
		{
			if (!visit[p.first])
				dfs(p.first,pos,val^p.second);	
			else
				insert(val^p.second^v[p.first]);
		} 
}

int main()
{
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%lld",&s,&t,&d);
		g[s].push_back({t,d});
		g[t].push_back({s,d});
	}
	dfs(1,0,0);
	LL ans=getans(v[n]);
	cout<<ans;
	return ~~(0^_^0);
}