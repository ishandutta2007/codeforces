#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

template<typename TT,int V,int E> struct DinicFlow
{
	int ds[V+1],q[V+1],nx[E+1],last[V+1],ver[E+1],now[V+1],n,edgesCount,S,T;
	TT cap[E+1],flow[E+1];
	DinicFlow():n(0),S(0),T(0),edgesCount(0){}
	DinicFlow(int _n):n(_n),S(0),T(0),edgesCount(0){}
	inline void reset(int _n)
	{
		edgesCount=0;
		n=_n;
		memset(last,-1,n*sizeof(int));
	}
	inline void addEdge(int v,int w,TT c,TT rc)
	{
		ver[edgesCount]=w; cap[edgesCount]=c;  flow[edgesCount]=0; nx[edgesCount]=last[v]; last[v]=edgesCount++;
		ver[edgesCount]=v; cap[edgesCount]=rc; flow[edgesCount]=0; nx[edgesCount]=last[w]; last[w]=edgesCount++;
	}
	inline bool bfs()
	{
		memset(ds,63,n*sizeof(int));
		int a=0,b=0;
		ds[T]=0;
		q[0]=T;
		while (a<=b)
		{
			int v=q[a++];
			for (int w=last[v];w>=0;w=nx[w])
			{
				if (cap[w^1]-flow[w^1] && ds[ver[w]]>ds[v]+1)
				{
					ds[ver[w]]=ds[v]+1;
					q[++b]=ver[w];
				}
			}
		}
		return ds[S]<1000000000;
	}
	TT dfs(int v,TT cur)
	{
		if (v==T) return cur;
		int ans = 0;
		for (int &w=now[v];w>=0;w=nx[w])
		{
			if (cap[w]-flow[w] && ds[ver[w]]==ds[v]-1)
			{
				TT rr=dfs(ver[w],min(cur,cap[w]-flow[w]));
				if (rr)
				{
					flow[w]+=rr;
					flow[w^1]-=rr;
					ans += rr;
					cur -= rr;
					if (!cur) break;
					//return rr;
				}
			}
		}
		return ans;
	}
	inline TT maxFlow()
	{
		TT ans=0;
		while (bfs())
		{
			memcpy(now,last,n*sizeof(int));
			TT tf;
			while (tf=dfs(S,1000000000)) ans+=tf;
		}
		return ans;
	}
};


const int maxN = 210;
int d[maxN][maxN];
DinicFlow < int, 205, 2100 > F;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	F.reset(n + 2);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u;
		--v;
		F.addEdge(u, v, w, w);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			memset(F.flow, 0, sizeof(F.flow));
			F.S = i;
			F.T = j;
			d[i][j] = d[j][i] = F.maxFlow();
		}
	}

	int best = 0;
	vector < int > res(n);
	for (int i = 0; i < n; ++i) {
		res[i] = i;
	}
	for (int i = 0; i < 1; ++i) {
		vector < int > order;
		order.push_back(i);
		vector < bool > used(n, false);
		used[i] = true;

		int score = 0;
		while (order.size() != n) {
			int best = -1, index = -1;
			for (int j = 0; j < n; ++j) {
				if (!used[j] && d[order.back()][j] > best) {
					best = d[order.back()][j];
					index = j;
				}
			}
			score += best;
			order.push_back(index);
			used[index] = true;
		}

		if (score > best) {
			best = score;
			res = order;
		}
	}

	printf("%d\n", best);
	for (int i = 0; i < res.size(); ++i) {
		printf("%d ", res[i] + 1);
	}
	printf("\n");


	return 0;
}