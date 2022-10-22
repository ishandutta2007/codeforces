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

//here
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MN 3010
#define INF (1LL<<30)

struct MinimumCostMaximumFlow {
    typedef int Index; typedef int Flow; typedef int Cost;
    static const Flow InfCapacity = INF;
    struct Edge {
        Index to; Index rev;
        Flow capacity; Cost cost;
    };
    vector<vector<Edge> > g;
    void init(Index n) { g.assign(n, vector<Edge>()); }
    void add(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
        Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0; e.cost = cost, f.cost = -cost;
        g[i].push_back(e); g[j].push_back(f);
        g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
    }
    void addB(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
        add(i, j, capacity, cost);
        add(j, i, capacity, cost);
    }
    pair<Cost,Flow> minimumCostMaximumFlow(Index s, Index t, Flow f = InfCapacity, bool bellmanFord = false) {
        int n = g.size();
        vector<Cost> dist(n); vector<Index> prev(n); vector<Index> prevEdge(n);
        pair<Cost,Flow> total = make_pair(0, 0);
        vector<Cost> potential(n);
        while(f > 0) {
            fill(dist.begin(), dist.end(), INF);
            if(bellmanFord || total.second == 0) {
                dist[s] = 0;
                rep(k, n) {
                    bool update = false;
                    rep(i, n) if(dist[i] != INF)
                    for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
                        const Edge &e = g[i][ei];
                        if(e.capacity <= 0) continue;
                        Index j = e.to; Cost d = dist[i] + e.cost;
                        if(dist[j] > d) {
                            dist[j] = d; prev[j] = i; prevEdge[j] = ei;
                            update = true;
                        }
                    }
                    if(!update) break;
                }
            }else {
                vector<bool> vis(n);
                priority_queue<pair<Cost,Index> > q;
                q.push(make_pair(-0, s)); dist[s] = 0;
                while(!q.empty()) {
                    Index i = q.top().second; q.pop();
                    if(vis[i]) continue;
                    vis[i] = true;
                    for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
                        const Edge &e = g[i][ei];
                        if(e.capacity <= 0) continue;
                        Index j = e.to; Cost d = dist[i] + e.cost + potential[i] - potential[j];
                        if(d < dist[i])  d = dist[i];    //
                        if(dist[j] > d) {
                            dist[j] = d; prev[j] = i; prevEdge[j] = ei;
                            q.push(make_pair(-d, j));
                        }
                    }
                }
            }
            if(dist[t] == INF) break;
            if(!bellmanFord) for(Index i = 0; i < n; i ++) potential[i] += dist[i];
            Flow d = f; Cost distt = 0;
            for(Index v = t; v != s; ) {
                Index u = prev[v]; const Edge &e = g[u][prevEdge[v]];
                d = min(d, e.capacity); distt += e.cost; v = u;
            }
            f -= d; total.first += d * distt; total.second += d;
            for(Index v = t; v != s; v = prev[v]) {
                Edge &e = g[prev[v]][prevEdge[v]];
                e.capacity -= d; g[e.to][e.rev].capacity += d;
            }
        }
        return total;
    }
} Flow;

int n, p, s;
int a[3010], b[3010];
int S, T, A, B;
vi v1, v2;

int main() {
	scanf("%d %d %d", &n, &p, &s);
	int N = n;
	S = n++;
	T = n++;
	A = n++;
	B = n++;

	Flow.init(n);

	rep(i, N) {
		scanf("%d", &a[i]);

		Flow.add(S, i, 1, 0);
		Flow.add(i, A, 1, -a[i]);
	}

	rep(i, N) {
		scanf("%d", &b[i]);
		Flow.add(i, B, 1, -b[i]);
	}

	Flow.add(A, T, p, 0);
	Flow.add(B, T, s, 0);

	printf("%d\n", -Flow.minimumCostMaximumFlow(S, T, s + p, 1).fi);

	rep(i, N) {
		for (auto e : Flow.g[i]) {
			if (e.capacity == 0 && Flow.g[e.to][e.rev].capacity == 1) {
				if (e.to == A) {
					v1.pb(i);
				} else if (e.to == B) {
					v2.pb(i);
				}
			}
		}
	}

	rep(i, p) {
		printf("%d%c", v1[i] + 1, i == p - 1 ? '\n' : ' ');
	}
	rep(i, s) {
		printf("%d%c", v2[i] + 1, i == s - 1 ? '\n' : ' ');
	}

	return 0;
}