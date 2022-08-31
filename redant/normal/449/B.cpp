#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

template <typename T>
class Graph {
public:
    struct Edge {
        int from;
        int to;
        int train;
        T weight = 0;
        Edge() {} 
        Edge(int _f, int _t, T _w, int _tr = 0) : from(_f), to(_t), weight(_w), train(_tr) {}
    };

    Graph(int _n, T _inf) : n(_n), inf(_inf) {
        g.resize(n);
    }

    void addEdge(int from, int to, T weight, int tr = 0) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        int id = (int) edges.size();
        edges.push_back({from, to, weight, tr});
        g[from].push_back(id);
    }
   
    vector<Edge> edges;
    vector<vector<int> > g;
    int n;

    // -------- Dijkstra --------
    struct State {
        int at;
        T dist;
        State() {}
        State(int _at, T _d) : at(_at), dist(_d){}
        bool operator<(const State &other) const {
            return dist > other.dist;
        }
    };

    vector<T> dist;
    T inf;
    
    void check_dij(priority_queue<State> &pq, int u, T newDist) {
        if (newDist < dist[u]) { 
            dist[u] = newDist;
            pq.emplace(State(u, newDist));
        }
    }

    void dijkstra(vector<int> sources) {
        if (n == 0) return;
        dist.assign(n, inf);

        priority_queue<State> pq;
        for (int s : sources) check_dij(pq, s, 0);

        while (!pq.empty()) {
            State top = pq.top(); pq.pop();
            // cout << top.at << ", " << top.dist << endl;
            if (top.dist > dist[top.at]) continue;
            for (int eid : g[top.at]) {
                Edge &e = edges[eid];
                check_dij(pq, e.to, top.dist + e.weight);
            }
        }
    }
};

template <typename T>
class UndirGraph : public Graph<T> {
public:
    using Graph<T>:: edges;
    using Graph<T>:: g;
    using Graph<T>:: n;

    UndirGraph(int _n, T _inf) : Graph<T>(_n, _inf) {}

    void addBiEdge(int from, int to, T weight, int tr = 0) {
        Graph<T>::addEdge(from, to, weight, tr);
        Graph<T>::addEdge(to, from, weight, tr);
    }
};

int n, m, k;

int solve() {
    cin >> n >> m >> k;

    const int start = 0;
    const LL inf = 1e15;

    UndirGraph<LL> graph(n, inf);

    REP(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        graph.addBiEdge(u, v, w);
    }

    REP(i, k) {
        int v, w;
        cin >> v >> w;
        --v;
        graph.addEdge(0, v, w, 1);
    }

    graph.dijkstra({start});

    vector<array<int, 2> > deg(n, {0, 0});
    vector<LL> &dist = graph.dist;

    int r = 0;

    for(auto &e : graph.edges) {
        if (dist[e.from] + e.weight == dist[e.to]) {
            ++deg[e.to][e.train];
        } else if (e.train) {
            r += 1;
        }
    }

    for(auto &e : graph.edges) {
        if (dist[e.from] + e.weight == dist[e.to]) {
            if (e.train && (deg[e.to][0] > 0 || deg[e.to][1] > 1)) {
                ++r;
                --deg[e.to][1];
            }
        }
    }

    return r;
}

int main() {
    setIO();
    cout<<solve()<<"\n";
    return 0;
}