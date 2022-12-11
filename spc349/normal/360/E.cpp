#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, int> pli;

vector <pii> from[10010];
vector <pii> G[10010];
long long dist[10010], ddd[10010];
int X[110], Y[110], W[110], L[110], R[110];
int s1, s2, f, n;
priority_queue <pli, vector <pli>, greater <pli> > q;

void Dij(int f, long long *dist) {
	for (int i = 1; i <= n; i++) {
		dist[i] = 0x3f3f3f3f3f3f3f3f;
	}
	dist[f] = 0, q.push(mp(dist[f], f));
	while (!q.empty()) {
		pli t = q.top(); q.pop();
		int x = t.se;
		if (dist[x] != t.fi) continue;
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i].fi, w = from[x][i].se;
			if (dist[v] > dist[x] + w) {
				dist[v] = dist[x] + w;
				q.push(mp(dist[v], v));
			}
		}
		for (int i = 0; i < G[x].size(); i++) {
			int v = G[x][i].fi, w = G[x][i].se;
			if (dist[v] > dist[x] + w) {
				dist[v] = dist[x] + w;
				q.push(mp(dist[v], v));
			}
		}
	}
}

int main () {
	int m, k; scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d%d", &s1, &s2, &f);
	for (int i = 0; i < m; i++) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		from[x].push_back(mp(y, c));
	}
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d%d", &X[i], &Y[i], &L[i], &R[i]);
		G[X[i]].push_back(mp(Y[i], R[i])), W[i] = R[i];
	}
	for (int it = 0; it < k; it++) {
		Dij(s1, dist), Dij(s2, ddd);
		int flag = 0;
		for (int i = 0; i < k; i++) {
			if (dist[X[i]] < ddd[X[i]]) {
				W[i] = L[i];
				flag = 1;
			}
		}
		if (!flag) break;
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		for (int i = 0; i < k; i++) {
			G[X[i]].push_back(mp(Y[i], W[i]));
		}
	}
	Dij(s1, dist), Dij(s2, ddd);
	if (dist[f] > ddd[f]) printf("LOSE\n");
	else {
		if (dist[f] == ddd[f]) printf("DRAW\n");
		else printf("WIN\n");
		for (int i = 0; i < k; i++) {
			printf("%d ", W[i]);
		}
		printf("\n");
	}
	return 0;
}