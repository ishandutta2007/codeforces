#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=300005,INF=1<<30;

// https://ei1333.github.io/library/graph/flow/dinic.hpp

/**
 * @brief Dinic()
 * @docs docs/dinic.md
 */
template < typename flow_t >
struct Dinic {
    const flow_t INF;
    
    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };
    
    vector< vector< edge > > graph;
    vector< int > min_cost, iter;
    
    explicit Dinic(int V)
    : INF(numeric_limits< flow_t >::max()),
    graph(V) {}
    
    void add_edge(int from, int to, flow_t cap, int idx = -1) {
        graph[from].emplace_back(
                                 (edge){to, cap, (int)graph[to].size(), false, idx});
        graph[to].emplace_back(
                               (edge){from, 0, (int)graph[from].size() - 1, true, idx});
    }
    
    bool build_augment_path(int s, int t) {
        min_cost.assign(graph.size(), -1);
        queue< int > que;
        min_cost[s] = 0;
        que.push(s);
        while (!que.empty() && min_cost[t] == -1) {
            int p = que.front();
            que.pop();
            for (auto &e: graph[p]) {
                if (e.cap > 0 && min_cost[e.to] == -1) {
                    min_cost[e.to] = min_cost[p] + 1;
                    que.push(e.to);
                }
            }
        }
        return min_cost[t] != -1;
    }
    
    flow_t find_min_dist_augment_path(int idx, const int t,
                                      flow_t flow) {
        if (idx == t) return flow;
        for (int &i = iter[idx]; i < (int)graph[idx].size(); i++) {
            edge &e = graph[idx][i];
            if (e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
                flow_t d =
                find_min_dist_augment_path(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        while (build_augment_path(s, t)) {
            iter.assign(graph.size(), 0);
            flow_t f;
            while ((f = find_min_dist_augment_path(s, t, INF)) > 0)
                flow += f;
        }
        return flow;
    }
    
    void output() {
        for (int i = 0; i < graph.size(); i++) {
            for (auto &e: graph[i]) {
                if (e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/"
                << e.cap + rev_e.cap << ")" << endl;
            }
        }
    }
    
    vector< bool > min_cut(int s) {
        vector< bool > used(graph.size());
        queue< int > que;
        que.emplace(s);
        used[s] = true;
        while (not que.empty()) {
            int p = que.front();
            que.pop();
            for (auto &e: graph[p]) {
                if (e.cap > 0 and not used[e.to]) {
                    used[e.to] = true;
                    que.emplace(e.to);
                }
            }
        }
        return used;
    }
};

template < typename flow_t, template < typename > class F >
struct MaxFlowLowerBound {
    F< flow_t > flow;
    vector< flow_t > in, up;
    typename F< flow_t >::edge *latte, *malta;
    int X, Y, V;
    flow_t sum;
    
    MaxFlowLowerBound(int V)
    : flow(V + 2),
    in(V),
    X(V),
    Y(V + 1),
    V(V),
    sum(0) {}
    
    void add_edge(int from, int to, flow_t low, flow_t high) {
        assert(from != to);
        flow.add_edge(from, to, high - low, up.size());
        in[from] -= low;
        in[to] += low;
        up.emplace_back(high);
    }
    
    void build() {
        for (int i = 0; i < V; i++) {
            if (in[i] > 0) {
                flow.add_edge(X, i, in[i]);
                sum += in[i];
            } else if (in[i] < 0) {
                flow.add_edge(i, Y, -in[i]);
            }
        }
    }
    
    bool can_flow(int s, int t) {
        assert(s != t);
        flow.add_edge(t, s, flow.INF);
        latte = &flow.graph[t].back();
        malta = &flow.graph[s].back();
        return can_flow();
    }
    
    bool can_flow() {
        build();
        auto ret = flow.max_flow(X, Y);
        return ret >= sum;
    }
    
    flow_t max_flow(int s, int t) {
        if (can_flow(s, t)) {
            return flow.max_flow(s, t);
        } else {
            return -1;
        }
    }
    
    flow_t min_flow(int s, int t) {
        if (can_flow(s, t)) {
            auto ret   = flow.INF - latte->cap;
            latte->cap = malta->cap = 0;
            return ret - flow.max_flow(t, s);
        } else {
            return -1;
        }
    }
    
    vector<int> output(int M) {
        vector< int > ans(M);
        for (int i = 0; i < flow.graph.size(); i++) {
            for (auto &e: flow.graph[i]) {
                if (!e.isrev && ~e.idx) ans[e.idx] = up[e.idx] - e.cap;
            }
        }
        return ans;
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> S(N),A(N),B(N);
    for(int i=0;i<N;i++) cin>>S[i];
    for(int i=0;i<N;i++) cin>>A[i];
    vector<pair<int,int>> E(M);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        E[i]=mp(a,b);
        B[a]--;
        B[b]--;
    }
    for(int i=0;i<N;i++){
        if(S[i]){
            if(abs(A[i]-B[i])&1){
                cout<<"NO\n";
                return 0;
            }
            if(abs(B[i])<abs(A[i])){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    
    MaxFlowLowerBound<int,Dinic> G(N+M+2);
    int s=M+N,t=M+N+1;
    for(int i=0;i<M;i++){
        auto [a,b]=E[i];
        G.add_edge(s,i,1,1);
        G.add_edge(i,M+a,0,1);
        G.add_edge(i,M+b,0,1);
    }
    ll needsum=0;
    for(int i=0;i<N;i++){
        if(S[i]==0){
            G.add_edge(M+i,t,0,M);
        }else{
            int need=(A[i]-B[i])/2;
            G.add_edge(M+i,t,need,need);
            needsum+=need;
        }
    }
    
    if(needsum>M){
        cout<<"NO\n";
        return 0;
    }
    
    if(G.max_flow(s,t)!=M){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    auto res=G.output(3*M+N);
    for(int i=0;i<M;i++){
        if(res[3*i+1]) cout<<E[i].se+1<<" "<<E[i].fi+1<<"\n";
        else cout<<E[i].fi+1<<" "<<E[i].se+1<<"\n";
    }
}