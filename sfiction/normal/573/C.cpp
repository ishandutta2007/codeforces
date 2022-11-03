#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10, MAXM = MAXN;

struct Edge{
	int v;
	Edge *next;
}e[MAXM << 1];

int edgeCnt;

int deg[MAXN], leg[MAXN];
Edge *E[MAXN];

bool del[MAXN];

void addEdge(int u, int v){
	e[edgeCnt] = (Edge){v, E[u]};
	E[u] = e + edgeCnt++;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
		++deg[u], ++deg[v];
	}
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 1){
			del[i] = true;
			for (int pre = i, u = E[i]->v; !del[u] && deg[u] == 2;){
				del[u] = true;
				int t = u;
				u = E[u]->v != pre ? E[u]->v : E[u]->next->v;
				pre = t;
			}
		}
	bool flag = false;
	for (int i = 1; i <= n; ++i)
		if (!del[i]){
			for (Edge *p = E[i]; p; p = p->next)
				leg[i] += del[p->v];
		}
	for (int i = 1; i <= n; ++i)
		if (!del[i]){
			int cnt = 0;
			for (Edge *p = E[i]; p; p = p->next)
				if (!del[p->v])
					cnt += deg[p->v] - min(leg[p->v], 2) > 1;
			if (cnt > 2){
				flag = true;
				break;
			}
		}
	puts(flag ? "No" : "Yes");
	return 0;
}