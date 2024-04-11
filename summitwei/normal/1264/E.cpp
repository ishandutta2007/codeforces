#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 55

template<typename T, typename C>
struct mcmf{
	static constexpr T eps = (T) 1e-9;
	struct edge{
		int from, to;
		T c, f;
		C cost;
	};
	vector<vector<int> > g;
	vector<edge> edges;
	vector<C> d;
	vector<bool> in_queue;
	vector<int> q, pe;
	int n, source, sink;
	T flow;
	C cost;
	mcmf(int n, int source, int sink): n(n), source(source), sink(sink), g(n), d(n), in_queue(n), pe(n){
		assert(0 <= source && source < n && 0 <= sink && sink < n && source != sink);
		flow = cost = 0;
	}
	void clear_flow(){
		for(const edge &e: edges) e.f = 0;
		flow = 0;
	}
	void add(int from, int to, T forward_cap, T backward_cap, C cost){
		assert(0 <= from && from < n && 0 <= to && to < n);
		g[from].push_back((int) edges.size());
		edges.push_back({from, to, forward_cap, 0, cost});
		g[to].push_back((int) edges.size());
		edges.push_back({to, from, backward_cap, 0, -cost});
	}
	bool expath(){
		fill(d.begin(), d.end(), numeric_limits<C>::max());
		q.clear();
		q.push_back(source);
		d[source] = 0;
		in_queue[source] = true;
		int beg = 0;
		bool found = false;
		while(beg < q.size()){
			int i = q[beg ++];
			if(i == sink) found = true;
			in_queue[i] = false;
			for(int id : g[i]){
				const edge &e = edges[id];
				if(e.c - e.f > eps && d[i] + e.cost < d[e.to]){
					d[e.to] = d[i] + e.cost;
					pe[e.to] = id;
					if(!in_queue[e.to]){
						q.push_back(e.to);
						in_queue[e.to] = true;
					}
				}
			}
		}
		if(found){
			T push = numeric_limits<T>::max();
			int v = sink;
			while(v != source){
				const edge &e = edges[pe[v]];
				push = min(push, e.c - e.f);
				v = e.from;
			}
			v = sink;
			while(v != source){
				edge &e = edges[pe[v]];
				e.f += push;
				edge &back = edges[pe[v] ^ 1];
				back.f -= push;
				v = e.from;
			}
			flow += push;
			cost += push * d[sink];
		}
		return found;
	}
	pair<T, C> get_mcmf(){
		while(expath()){ }
		return {flow, cost};
	}
};

int n, m;
int e[MN][MN];
int p[MN*MN], q[MN*MN];
int ans[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    F0R(_, m){
        int u, v;
        cin >> u >> v;
        e[u][v] = 1;
    }
    int k=n*(n-1)/2;
    mcmf<int, int> g(1+k+n+1, 0, k+n+1);
    int ptr = 0;
    FOR(i, 1, n){
        FOR(j, i+1, n){
            ++ptr;
            p[ptr] = i; q[ptr] = j;
            g.add(0, ptr, 1, 0, 0);
            if(!e[j][i]){
                g.add(ptr, k+i, 1, 0, 0);
            }
            if(!e[i][j]){
                g.add(ptr, k+j, 1, 0, 0);
            }
        }
        F0R(j, n){
            g.add(k+i, k+n+1, 1, 0, j);
        }
    }
    auto cur = g.get_mcmf();
    
    for(auto ee : g.edges){
        if(ee.from <= k && ee.f == 1 && ee.from >= 1){
            ans[ee.to-k][p[ee.from]+q[ee.from]-(ee.to-k)] = 1;
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}