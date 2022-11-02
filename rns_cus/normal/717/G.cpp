#include <bits/stdc++.h>
using namespace std;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxnodes = 51000;

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
	int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s, int t, int cap, int cost) {
	Edge a = {t, 0, cap, cost, graph[t].size()};
	Edge b = {s, 0, 0, -cost, graph[s].size()};
	graph[s].push_back(a);
	graph[t].push_back(b);
}

void bellmanFord(int s, int dist[]) {
	fill(dist, dist + nodes, INT_MAX);
	dist[s] = 0;
	int qt = 0;
	q[qt++] = s;
	for (int qh = 0; (qh - qt) % nodes != 0; qh++) {
		int u = q[qh % nodes];
		inqueue[u] = false;
		for (int i = 0; i < (int) graph[u].size(); i++) {
			Edge &e = graph[u][i];
			if (e.cap <= e.f) continue;
			int v = e.to;
			int ndist = dist[u] + e.cost;
			if (dist[v] > ndist) {
				dist[v] = ndist;
				if (!inqueue[v]) {
					inqueue[v] = true;
					q[qt++ % nodes] = v;
				}
			}
		}
	}
}

pii minCostFlow(int s, int t, int maxf) {
// bellmanFord can be safely commented if edges costs are non-negative
	bellmanFord(s, pot);
	int flow = 0;
	int flowCost = 0;
	while (flow < maxf) {
		priority_queue<ll, vector<ll>, greater<ll> > q;
		q.push(s);
		fill(prio, prio + nodes, INT_MAX);
		prio[s] = 0;
		curflow[s] = INT_MAX;
		while (!q.empty()) {
			ll cur = q.top();
			int d = cur >> 32;
			int u = cur;
			q.pop();
			if (d != prio[u])
				continue;
			for (int i = 0; i < (int) graph[u].size(); i++) {
				Edge &e = graph[u][i];
				int v = e.to;
				if (e.cap <= e.f) continue;
				int nprio = prio[u] + e.cost + pot[u] - pot[v];
				if (prio[v] > nprio) {
					prio[v] = nprio;
					q.push(((ll) nprio << 32) + v);
					prevnode[v] = u;
					prevedge[v] = i;
					curflow[v] = min(curflow[u], e.cap - e.f);
				}
			}
		}
		if (prio[t] == INT_MAX) break;
		for (int i = 0; i < nodes; i++)
			pot[i] += prio[i];
		int df = min(curflow[t], maxf - flow);
		flow += df;
		for (int v = t; v != s; v = prevnode[v]) {
			Edge &e = graph[prevnode[v]][prevedge[v]];
			e.f += df;
			graph[v][e.rev].f -= df;
			flowCost += df * e.cost;
		}
	}
	return make_pair(flow, flowCost);
}

char s[501], ss[501];

int main() {
    ///freopen("g.in", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i ++) {
        int c;
        scanf("%s %d", ss, &c);
        int nn = strlen(ss);
        for(int j = 1; j + nn - 1 <= n; j ++) {
            bool ok = 1;
            for(int k = 0; k < nn; k ++) if(ss[k] != s[j + k]) {ok = 0; break;}
            if(ok) {
                addEdge(j, j + nn, 1, -c);
            }
        }
    }
    int x;
    scanf("%d", &x);
    addEdge(0, 1, x, 0);
    for(int i = 1; i <= n; i ++) addEdge(i, i + 1, n, 0);
    pair<int, int> res = minCostFlow(0, n + 1, INT_MAX);
    printf("%d\n", -res.second);
}