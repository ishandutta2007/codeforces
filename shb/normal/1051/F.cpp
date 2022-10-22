#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long LL;

int N,M; 
int L[200010],R[200010];
bool intree[200010];
LL len[200010];
int f[200010],num[200010];
LL ret[50][100010],d[100010];
vector<pair<int,LL> >e[100010],et[100010];
bool special[100010];
vector<int>spe,spee;

int find(int x)
{
	return x == f[x]?x:f[x] = find(f[x]);
}

bool inq[100010];
queue<int>q;
const LL INF = 1e18;
void SPFA(int root)
{
	for (int i=1;i<=N;i++)
	{
		inq[i] = false;
		d[i] = INF;
	}
	q.push(root);
	d[root] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto t:e[u])
		{
			int v = t.X;
			LL lt = t.Y;
			if (d[u] + lt < d[v])
			{
				d[v] = d[u] + lt;
				if (!inq[v])
				{
					q.push(v);
					inq[v] = true;
				}
			}
		}
		inq[u] = false;
	}
}

LL depth[100010];
int anc[100010][20],depth2[100010];
void dfs(int u,int ff)
{
	for (auto t:et[u])
	{
		int v = t.X;
		LL lt = t.Y;
		if (v == ff) continue;
		depth[v] = depth[u] + lt;
		depth2[v] = depth2[u] + 1;
		anc[v][0] = u;
		for (int i=1;i<20;i++)anc[v][i] = anc[anc[v][i-1]][i-1];
		dfs(v,u);
	}
}

int lca(int x,int y)
{
	if (depth2[x] < depth2[y]) swap(x,y);
	int delta = depth2[x] - depth2[y];
	for (int i=19;i>=0;i--)
	if (delta & (1 << i)) x = anc[x][i];
	if (x == y) return x;
	for (int i=19;i>=0;i--)
	if (anc[x][i] != anc[y][i]) 
	{
		x = anc[x][i];
		y = anc[y][i];
	}
	return anc[x][0];
}

LL dis(int x,int y)
{
	int LCA = lca(x,y);
	return depth[x] + depth[y] - 2 * depth[LCA];
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)f[i] = i;
	for (int i=1;i<=M;i++)scanf("%d%d%lld",&L[i],&R[i],&len[i]);
	memset(special,false,sizeof(special));
	for (int i=1;i<=M;i++)
	{
		int u = find(L[i]), v = find(R[i]);
		e[L[i]].push_back(make_pair(R[i],len[i]));
		e[R[i]].push_back(make_pair(L[i],len[i]));
		if (u == v)
		{
			intree[i] = false;
			special[L[i]] = special[R[i]] = true;
			spee.push_back(i);
		}
		else
		{
			intree[i] = true;
			et[L[i]].push_back(make_pair(R[i],len[i]));
			et[R[i]].push_back(make_pair(L[i],len[i]));
			f[u] = v;
		}
	}
	dfs(1,0);
	for (int i=1;i<=N;i++)
	if (special[i]) spe.push_back(i);
	int SN = spe.size();
	for (int i=0;i<SN;i++)
	{
		SPFA(spe[i]);
		num[spe[i]] = i;
		for (int j=1;j<=N;j++)ret[i][j] = d[j];
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		LL ans = dis(u,v);
		for (auto i:spee)
		{
			ans = min(ans,ret[num[L[i]]][u] + ret[num[R[i]]][v] + len[i]);
			ans = min(ans,ret[num[R[i]]][u] + ret[num[L[i]]][v] + len[i]);
		}
		printf("%lld\n",ans);
	}
}