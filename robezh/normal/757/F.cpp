/*
 *  Dominator tree in O(M log(N)/log(2+M/N)) time, O(M+N) space
 *  Algorithm by T.Lengauer and R.E.Tarjan
 *  This is essentially the directed version of articulation points
 *  takes 0.42s for N=2e5, M = 3e5 (+ dijkstras)
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

struct edge{
    int to, cost;
    edge(int _to, int _cost){
        to = _to, cost = _cost;
    }
};

int n,m,s;
vector<edge> G[N];
ll dis[N];

struct Dominator{
    struct min_DSU{
        vector<int> par, val;
        vector<int> const&semi;
        min_DSU(int N, vector<int> const&semi):par(N, -1),val(N), semi(semi){
            iota(val.begin(), val.end(), 0);
        }
        void comp(int x){
            if(par[par[x]]!=-1){
                comp(par[x]);
                if(semi[val[par[x]]]<semi[val[x]])
                    val[x] = val[par[x]];
                par[x]=par[par[x]];
            }
        }
        int f(int x){
            if(par[x]==-1) return x;
            comp(x);
            return val[x];
        }
        void link(int x, int p){
            par[x] = p;
        }
    };
    int N;
    vector<vector<int> > G, rG;
    vector<int> idom, order;
    Dominator(int _N):N(_N), G(N), rG(N){}
    void add_edge(int a, int b){
        G[a].emplace_back(b);
        rG[b].emplace_back(a);
    }
    vector<int> calc_dominators(int S){
        idom.assign(N, -1);
        vector<int> par(N, -1), semi(N, -1);
        vector<vector<int> > bu(N);
        stack<int> s;
        s.emplace(S);
        while(!s.empty()){
            int a=s.top();s.pop();
            if(semi[a]==-1){
                semi[a] = order.size();
                order.emplace_back(a);
                for(int i=0;i<(int)G[a].size();++i){
                    if(semi[G[a][i]]==-1){
                        par[G[a][i]]=a;
                        s.push(G[a][i]);
                    }
                }
            }
        }
        min_DSU uni(N, semi);
        for(int i=(int)order.size()-1;i>0;--i){
            int w=order[i];
            for(int f:rG[w]){
                int oval = semi[uni.f(f)];
                if(oval>=0 && semi[w]>oval) semi[w] = oval;
            }
            bu[order[semi[w]]].push_back(w);
            uni.link(w, par[w]);
            while(!bu[par[w]].empty()){
                int v = bu[par[w]].back(); bu[par[w]].pop_back();
                int u=uni.f(v);
                idom[v] = semi[u] < semi[v] ? u : par[w];
            }
        }
        for(int i=1;i<(int)order.size();++i){
            int w=order[i];
            if(idom[w] != order[semi[w]])
                idom[w] = idom[idom[w]];
        }
        idom[S]=-1;
        return idom;
    }
};

void dijkstra(int s){
    fill(dis, dis+N, INF);
    dis[s] = 0;
    priority_queue<P, vector<P>, greater<P> > pque;
    pque.push({0, s});

    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        int i = p.second;
        ll dist = p.first;
        if(dist > dis[i]) continue;
        for(edge e : G[i]){
            if(e.cost + dis[i] < dis[e.to]){
                dis[e.to] = e.cost + dis[i];
                pque.push({dis[e.to], e.to});
            }
        }
    }
}

int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s;
    s--;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    dijkstra(s);
    Dominator D(n);
    for(int i = 0; i < n; i++) {
        for(auto e : G[i]) {
            if(dis[i] + e.cost == dis[e.to]) D.add_edge(i, e.to);
        }
    }
    vector<int> par = D.calc_dominators(s);
//    for(int i = 1; i <= n; i++) cout << i + 1 << ", " << par[i] << endl;
    for(int i = (int)D.order.size() - 1; i > 0; i--) {
        int e = D.order[i];
        res[par[e]] += ++res[e];
    }
    res[s] = 0;
    cout << *max_element(res, res + n) << endl;

}