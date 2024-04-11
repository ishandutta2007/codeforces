#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 1<<10;

int n, k;
int start[SIZE], len[SIZE], money[SIZE];


const int64 INF = 1000000000000000000LL;
const int VERTS = 2*SIZE + 16;

struct Edge {
	int u, v;
	int cap, flow;
	int64 cost;
};
vector<Edge> edges;
vector<int> nbr[VERTS];

void AddEdge(int u, int v, int cap, int cost) {
	Edge x;
	x.u = u;
	x.v = v;
	x.cap = cap;
	x.cost = cost;
	x.flow = 0;
	int e1 = edges.size();
	edges.push_back(x);
	x.u = v;
	x.v = u;
	x.cap = 0;
	x.cost = -cost;
	x.flow = 0;
	int e2 = edges.size();
	edges.push_back(x);

	nbr[u].push_back(e1);
	nbr[v].push_back(e2);
}
inline int anti(int x) { return x ^ 1; }

int v, s, t;
bool used[VERTS];
int64 dist[VERTS];
int father[VERTS];
int64 phi[VERTS];

int ans[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &k);
	for (int i = 0; i<n; i++)
		scanf("%d%d%d", &start[i], &len[i], &money[i]);

	v = 2*n;
	s = v++;
	t = v++;
	
	for (int i = 0; i<n; i++) {
		AddEdge(i, i+n, 1, -money[i]);
		AddEdge(s, i, 1000, 0);
		AddEdge(i+n, t, 1000, 0);
	}
	AddEdge(s, t, 1000, 0);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (start[i] + len[i] <= start[j])
				AddEdge(n+i, j, 1000, 0);

	for (int i = 0; i<n; i++) {
		int64 cstsum = 0;
		for (int j = 0; j<n; j++)
			if (start[j] < start[i])
				cstsum += money[j];
		phi[i] = -cstsum;
		phi[n+i] = phi[i] - money[i];
		if (phi[t] > phi[n+i])
			phi[t] = phi[n+i];
	}
	

  	int64 flowcost = 0;
  	for (int f = 0; f<k; f++) {
		memset(used, 0, sizeof(used));
		memset(dist, 63, sizeof(dist));
		memset(father, -1, sizeof(father));
		dist[s] = 0;

		while (1) {
			int64 mind = INF;
			int best = -1;
			for (int i = 0; i<v; i++) if (!used[i])
				if (mind > dist[i]) {
					mind = dist[i];
					best = i;
				}
			if (best < 0) break;
			used[best] = true;
			for (int i = 0; i<nbr[best].size(); i++) {
				int ei = nbr[best][i];
				if (edges[ei].flow == edges[ei].cap) continue;
				int dd = edges[ei].v;

				int64 edgel = edges[ei].cost + phi[best] - phi[dd];
//				assert(edgel>=0);
				int64 newd = dist[best] + edgel;
				if (dist[dd] > newd) {
					dist[dd] = newd;
					father[dd] = ei;
				}
			}
		}
		if (dist[t] >= INF) break;

		int mincap = 1;
		for (int i = t; ;) {
			int ei = father[i];
			if (ei < 0) break;
			flowcost += mincap * edges[ei].cost;
			edges[ei].flow += mincap;
			edges[anti(ei)].flow -= mincap;
			i = edges[ei].u;
		}

		for (int i = 0; i<v; i++) if (dist[i] < INF)
			phi[i] += dist[i];
   	}


   	for (int i = 0; i<n; i++)
   		for (int j = 0; j<nbr[i].size(); j++) {
   			Edge e = edges[nbr[i][j]];
   			if (e.cost == 0) continue;
   			if (e.flow) ans[i] = true;
   		}

//   	printf("%I64d\n", -flowcost);
   	for (int i = 0; i<n; i++) printf("%d ", ans[i]);

	return 0;
}