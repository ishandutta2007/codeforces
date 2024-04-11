#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000000;

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

int main()
{
    int n;
    cin >> n;
    int a[3002], b[3002];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    Flow<int> g(n + 2, n, n + 1);
    for(int i = n - 1; i >= 0; i--){
        bool c[105]{0};
        for(int j = 1; j <= 100; j++){
            if(a[i] % j == 0) c[j] = true;
        }
        for(int j = i - 1; j >= 0; j--){
            if(c[a[j]]){
                g.add_edge(i, j, INF);
                for(int k = 1; k <= a[j]; k++){
                    if(a[j] % k == 0) c[k] = false;
                }
            }
        }
    }
    int s = 0;
    for(int i = 0; i < n; i++){
        if(b[i] > 0){
            g.add_edge(n, i, b[i]);
            s += b[i];
        }
        else g.add_edge(i, n + 1, -b[i]);
    }
    cout << s - g.max_flow() << endl;
}