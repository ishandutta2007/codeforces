#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Edge
{
    int to;
    T cap;
    int rev;
    int id;
};

template <typename T>
struct Flow
{
    int n;
    int source;
    int sink;
    T current_flow;
    std::vector<int> d;
    std::vector<int> nx;
    std::vector<std::vector<Edge<T>>> g;
    std::vector<std::pair<int, int>> epos;
    
    Flow(){}
    
    Flow(int n, int source, int sink) : n(n), source(source), sink(sink), current_flow(0){
        d.resize(n);
        nx.resize(n);
        g.resize(n);
    }
    
    void add_edge(int from, int to, T cap){
        epos.push_back(std::pair<int, int>(from, (int)g[from].size()));
        g[from].push_back((Edge<T>){to, cap, (int)g[to].size(), (int)epos.size() - 1});
        g[to].push_back((Edge<T>){from, 0, (int)g[from].size() - 1, -1});
    }
    
    T delete_edge(int id){
        Edge<T> &e = g[epos[id].first][epos[id].second];
        Edge<T> &re = g[e.to][e.rev];
        int u = re.to, v = e.to;
        T delete_f = re.cap;
        e.cap = 0;
        re.cap = 0;
        T reverse_f = delete_f - add_flow(u, v, delete_f);
        add_flow(u, source, reverse_f);
        add_flow(sink, v, reverse_f);
        current_flow -= reverse_f;
        return current_flow;
    }
    
    void bfs(int s){
        fill(d.begin(), d.end(), -1);
        std::queue<int> que;
        d[s] = 0;
        que.push(s);
        while(que.size()){
            int u = que.front();
            que.pop();
            for(Edge<T> &e : g[u]){
                int v = e.to;
                Edge<T> &re = g[v][e.rev];
                if(re.cap > 0 && d[v] == -1){
                    d[v] = d[u] + 1;
                    que.push(v);
                }
            }
        }
    }
    
    T dfs(int u, int s, T f){
        if(u == s) return f;
        for(int &i = nx[u]; i < (int)g[u].size(); i++){
            Edge<T> &e = g[u][i];
            int v = e.to;
            if(d[v] >= d[u] || e.cap == 0) continue;
            if(f == -1) f = e.cap;
            else f = std::min(f, e.cap);
            T fl = dfs(v, s, f);
            if(fl > 0){
                e.cap -= fl;
                g[e.to][e.rev].cap += fl;
                return fl;
            }
        }
        return 0;
    }
    
    T add_flow(int r, int s, T max_f){
        T res = 0;
        while(true){
            if(max_f == 0) return res;
            bfs(s);
            if(d[r] == -1) return res;
            for(int i = 0; i < n; i++) nx[i] = 0;
            for(T f; (f = dfs(r, s, max_f)) > 0;){
                res += f;
                if(max_f != -1) max_f -= f;
            }
        }
    }
    
    T max_flow(T max_f = -1){
        if(max_f != -1){
            max_f -= current_flow;
            if(max_f < 0){
                current_flow -= add_flow(sink, source, -max_f);
                return current_flow;
            }
        }
        current_flow += add_flow(source, sink, max_f);
        return current_flow;
    }
    
    int get_flow(int id){
        Edge<T> &e = g[epos[id].first][epos[id].second];
        Edge<T> &re = g[e.to][e.rev];
        return re.cap;
    }
};

struct BipartiteMatching
{
    int p;
    int q;
    Flow<int> g;
    
    BipartiteMatching(){}
    
    BipartiteMatching(int p, int q) : p(p), q(q){
        g.n = p + q + 2;
        g.source = p + q;
        g.sink = p + q + 1;
        g.current_flow = 0;
        g.d.resize(g.n);
        g.nx.resize(g.n);
        g.g.resize(g.n);
        for(int i = 0; i < p; i++) g.add_edge(p + q, i, 1);
        for(int i = p; i < p + q; i++) g.add_edge(i, p + q + 1, 1);
    }
    
    void add_edge(int u, int v){
        g.add_edge(u, v + p, 1);
    }
    
    int delete_edge(int id){
        return g.delete_edge(id + p + q);
    }
    
    int max_matching(){
        return g.max_flow();
    }
    
    bool is_used(int id){
        return g.get_flow(id + p + q);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        BipartiteMatching g(n, n);
        int b[200005];
        for(int i = 0; i < n; i++){
            cin >> b[i];
            b[i]--;
            g.add_edge(i, b[i]);
        }
        int k = g.max_matching();
        int p[200005], q[200005];
        for(int i = 0; i < n; i++) p[i] = q[i] = -1;
        for(int i = 0; i < n; i++){
            if(g.is_used(i)){
                p[i] = b[i];
                q[b[i]] = i;
            }
        }
        vector<int> c[3];
        for(int i = 0; i < n; i++){
            if(p[i] == -1){
                if(q[i] == -1) c[0].push_back(i);
                else c[1].push_back(i);
            }
            else if(q[i] == -1) c[2].push_back(i);
        }
        if(k == n - 1 && c[0].size() == 1){
            int t0 = c[0][0];
            int t1 = q[b[t0]];
            p[t0] = b[t0];
            p[t1] = t0;
        }
        else{
            int l = c[0].size();
            if(l >= 2){
                for(int i = 0; i < l; i++){
                    p[c[0][i]] = c[0][(i + 1) % l];
                }
            }
            if(l == 1){
                int t = c[0][0];
                p[t] = c[2].back();
                c[2].pop_back();
                c[2].push_back(t);
            }
            for(int i = 0; i < (int)c[1].size(); i++){
                p[c[1][i]] = c[2][i];
            }
        }
        cout << k << "\n";
        for(int i = 0; i < n; i++) cout << p[i] + 1 << " ";
        cout << "\n";
    }
}