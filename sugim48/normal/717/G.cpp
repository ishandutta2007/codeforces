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

const int InfCost = 1000000000;
const int INF = 1000000;

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
    // void addB(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
    //     add(i, j, capacity, cost);
    //     add(j, i, capacity, cost);
    // }

    pair<Cost,Flow> minimumCostMaximumFlow(Index s, Index t, Flow f = InfCapacity, bool bellmanFord = false) {
        int n = g.size();
        vector<Cost> dist(n); vector<Index> prev(n); vector<Index> prevEdge(n);
        pair<Cost,Flow> total = make_pair(0, 0);
        vector<Cost> potential(n);
        while(f > 0) {
            fill(dist.begin(), dist.end(), InfCost);
            if(bellmanFord || total.second == 0) {
                dist[s] = 0;
                rep(k, n) {
                    bool update = false;
                    rep(i, n) if(dist[i] != InfCost)
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
            if(dist[t] == InfCost) break;
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

int n, m, x;
string s;
int p[110];

int main() {
	cin >> n >> s >> m;
	Flow.init(n + 1);

	rep(i, n) Flow.add(i, i + 1, INF, 0);

	rep(i, m) {

		string t;

		cin >> t >> p[i];

		int sz = t.size();

		for (int j = 0; j <= max(0, n - sz); ++j) {
			bool ok = 1;

			for (int k = 0, l = j; k < sz; ++k, ++l) {
				if (t[k] != s[l]) {
					ok = 0;
					break;
				}
			}

			if (ok) {
				Flow.add(j, j + sz, 1, -p[i]);
				//cout << j << " " << j + sz << " " << p[i] << endl;
			}
		}
	}

	cin >> x;

	pii ret = Flow.minimumCostMaximumFlow(0, n, x, true);
	cout << -ret.fi << endl;

	return 0;
}