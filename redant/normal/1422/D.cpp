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

const int SZ = 300005;

template <typename T>
class Graph {
public:
    struct Edge {
        int from;
        int to;
        T weight = 0;
        Edge() {} 
        Edge(int _f, int _t, T _w) : from(_f), to(_t), weight(_w) {}
    };

    Graph(int _n, T _inf) : n(_n), inf(_inf) {
        g.resize(n);
    }

    void addEdge(int from, int to, T weight = 1) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        int id = (int) edges.size();
        edges.push_back({from, to, weight});
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
        State(int _at, T _d) : at(_at), dist(_d) {}
        bool operator<(const State &other) const {
            return dist > other.dist;
        }
    };

    vector<T> dist;
    vector<int> dijPar;
    T inf;
    
    void check_dij(priority_queue<State> &pq, int u, int pu, T newDist) {
        if (newDist < dist[u]) {
            dist[u] = newDist;
            dijPar[u] = pu;
            pq.emplace(State(u, newDist));
        }
    }

    void dijkstra(vector<int> sources) {
        if (n == 0) return;
        dist.assign(n, inf);
        dijPar.assign(n, -1);

        priority_queue<State> pq;
        for (int s : sources) check_dij(pq, s, -1, 0);

        while (!pq.empty()) {
            State top = pq.top(); pq.pop();
            // cout << top.at << ", " << top.dist << endl;
            if (top.dist > dist[top.at]) continue;
            for (int eid : g[top.at]) {
                Edge &e = edges[eid];
                check_dij(pq, e.to, top.at, top.dist + e.weight);
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

    void addBiEdge(int from, int to, T weight = 1) {
        Graph<T>::addEdge(from, to, weight);
        Graph<T>::addEdge(to, from, weight);
    }
};

int n, m;
LL sx, sy, fx, fy;

LL solve() {
    cin >> n >> m;
    cin >> sx >> sy >> fx >> fy;

    vector<pair<array<LL, 2>, int>> loc(m);

    REP(i, m) {
        cin >> loc[i].F[0] >> loc[i].F[1];
        loc[i].S = i;
    }

    const int start = m, finish = m + 1;
    const LL inf = 1e15;

    UndirGraph<LL> graph(m+2, inf);

    auto get_dist = [](LL dx, LL dy) {
        return abs(dx) + abs(dy);
    };

    auto get_dist2 = [](LL dx, LL dy) {
        return min(abs(dx), abs(dy));
    };

    graph.addEdge(start, finish, get_dist(sx-fx, sy-fy));

    REP(i, m) {
        graph.addBiEdge(start, i, get_dist2(sx - loc[i].F[0], sy - loc[i].F[1]));
        graph.addBiEdge(i, finish, get_dist(fx - loc[i].F[0], fy - loc[i].F[1]));
    }

    sort(ALL(loc));
    REP(i, m-1) {
        graph.addBiEdge(loc[i].S, loc[i+1].S, abs(loc[i].F[0] - loc[i+1].F[0]));
    }

    REP(i, m) swap(loc[i].F[0], loc[i].F[1]);

    sort(ALL(loc));
    REP(i, m-1) {
        graph.addBiEdge(loc[i].S, loc[i+1].S, abs(loc[i].F[0] - loc[i+1].F[0]));
    }

    graph.dijkstra({start});

    return graph.dist[finish];
}

int main() {
    setIO();
    cout<<solve()<<"\n";    
    return 0;
}