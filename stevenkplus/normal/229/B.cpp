#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

const int inf = 1 << 30;
const int MAXN = 100100;

typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;

#define repi(i,a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define fi first
#define se second
#define pb push_back

int N, M;

bool vis[MAXN];
int mindist[MAXN];
vector<pii> edges[MAXN];
set<pii> busy;

bool isBusy(int a, int b) {
	return busy.find(pii(a, b)) != busy.end();
}

void dijkstra() {
	PQ pq;
	pq.push(pii(0, 0));
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		int to = p.se;
		int dist = p.fi;
		if (vis[to]) continue;
		vis[to] = true;
		while (isBusy(to, dist)) {
			dist++;
		}
		repi(i, edges[to]) {
			pii q = *i;
			int dest = q.se;
			int len = q.fi;
			int newdist = dist + len;
			if (!vis[dest] && newdist < mindist[dest]) {
				mindist[dest] = newdist;
				pq.push(pii(newdist, dest));
			}
		}
	}
}


int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c); a--; b--;
		edges[a].pb(pii(c, b));
		edges[b].pb(pii(c, a));
	}
	for(int i = 0; i < N; ++i) {
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; ++j) {
			int t;
			scanf("%d", &t);
			busy.insert(pii(i, t));
		}
	}
	for(int i = 0; i < N; ++i) {
		mindist[i] = inf;
	}
	dijkstra();
	int ans = mindist[N - 1];
	if (ans == inf) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}