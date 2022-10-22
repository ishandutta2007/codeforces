#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll INF = INT_MAX;

struct Edge {
	int id, to, cost;
	Edge(){}
	Edge(int id, int to, int cost) 
		: id (id), to(to), cost(cost) {}
};

int n, m, s, t;
ll L;
int U[10010], V[10010], W[10010];
vector<Edge> g[1010];
ll d[1010][1010];
pii pre[1010][1010];

typedef pair<ll, int> Data;
priority_queue<Data, vector<Data>, greater<Data>> que[1010];

int main() {
	cin >> n >> m >> L >> s >> t;
	rep(i, m) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		U[i] = a; V[i] = b; W[i] = w;
		g[a].eb(i,b,w);
		g[b].eb(i,a,w);
	}
	rep(i, 1010) rep(j, 1010) d[i][j] = INF;
	d[0][s] = 0;
	que[0].push(mp(0LL, s));

	for (int i=0;i<n;++i) {
		while (!que[i].empty()) {
			Data dt = que[i].top(); que[i].pop();
			int v = dt.se;
			if (dt.fi > d[i][v]) continue;
			for (Edge es : g[v]) {
				ll nc = d[i][v] + es.cost;
				if (es.cost == 0) {
					if (d[i+1][es.to] > nc) {
						d[i+1][es.to] = nc;
						pre[i+1][es.to] = mp(v, es.id);
						que[i+1].push(mp(nc, es.to));
					}
				} else {
					if (d[i][es.to] > nc) {
						d[i][es.to] = nc;
						pre[i][es.to] = mp(v, es.id);
						que[i].push(mp(nc, es.to));
					}
				}
			}
		}
	}

	if (d[0][t] < L) {
		puts("NO");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		if (d[i][t] != INF && d[i][t] <= L - i) {
			puts("YES");
			int zan = i, cur = t;
			ll u = L - d[i][t];
			while (cur != s) {
				pii p = pre[zan][cur];
				if (W[p.se]==0) {
					--zan;
					W[p.se] = (zan==0? u : 1);
					u -= W[p.se];
				}
				cur = p.fi;
			}
			assert(zan==0);
			assert(u==0);

			rep(i, m) {
				if (W[i] == 0) W[i] = INF;
				printf("%d %d %d\n", U[i], V[i], W[i]);
			}
			return 0;
		}
	}
	puts("NO");

	return 0;
}