#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int from, to;
    int capacity, flow, cost;

    Edge(){}

    Edge(int from, int to, int capacity, int flow, int cost){
        this->from = from;
        this->to = to;
        this->capacity = capacity;
        this->flow = flow;
        this->cost = cost;
    }
};

template<size_t t_N>
struct Min_Cost_Max_Flow{
    static const int k_Inf = 1e9 + 7;

    int n;
    vector<int> adjacent[t_N];
    vector<Edge> edges;

    int prev_edge[t_N];

    Min_Cost_Max_Flow(){
        n = 0;
    }

    void add_edge(int u, int v, int capacity, int cost){
        edges.push_back({u, v, capacity, 0, cost});
        edges.push_back({v, u, 0, 0, -cost});

        adjacent[u].push_back(edges.size() - 2);
        adjacent[v].push_back(edges.size() - 1);

        n = max(n, u + 1);
        n = max(n, v + 1);
    }

   pair<int, int> spfa(int from, int to){
        static bool in_queue[t_N];
        static int distance[t_N];
        static queue<int> q;

        for(int i = 0; i < n; ++i){
            in_queue[i] = false;
            distance[i] = k_Inf;
        }

        in_queue[from] = true;
        distance[from] = 0;
        q.push(from);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            in_queue[node] = false;

            for(int edge_index: adjacent[node]){
                Edge &edge = edges[edge_index];
                Edge &rev_edge = edges[(edge_index ^ 1)];
                int to = edge.to;

                int curr_distance = edge.cost + distance[node];
                if(edge.flow < edge.capacity && curr_distance < distance[to]){
                    distance[to] = curr_distance;
                    prev_edge[to] = edge_index;

                    if(!in_queue[to]){
                        in_queue[to] = true;
                        q.push(to);
                    }
                }
            }
        }

        int node = to, curr_flow = k_Inf, curr_cost = 0;
        while(node != from){
            int edge_index = prev_edge[node];
            Edge &edge = edges[edge_index];

            curr_flow = min(edge.capacity - edge.flow, curr_flow);
            curr_cost += edge.cost;

            node = edge.from;
        }

        curr_cost *= curr_flow;

        return {curr_flow, curr_cost};
    }

    pair<int, int> get_min_cost_max_flow(int from, int to){
        int flow = 0, cost = 0;
        while(true){
            auto [curr_flow, curr_cost] = spfa(from, to);
            if(!curr_flow)
                break;

            flow += curr_flow;
            cost += curr_cost;

            int node = to;
            while(node != from){
                int edge_index = prev_edge[node];
                Edge &edge = edges[edge_index];
                Edge &rev_edge = edges[(edge_index ^ 1)];

                edge.flow += curr_flow;
                rev_edge.flow -= curr_flow;

                node = edge.from;
            }
        }

        return {flow, cost};
    }
};

const int k_N = 250 + 6;
const int k_M = 26 + 6;

Min_Cost_Max_Flow<2 * k_N + k_M> mf;
int a[k_N], f[k_N];
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n; ++i){
        f[i] = 0;
        for(int bit = 0; bit < 30; ++bit)
            f[i] += (bool)((1 << bit) & a[i]);
    }

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            mf.add_edge(i, j + m + n, 1, f[j]);

    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            mf.add_edge(i + m, j + m + n, 1, (a[i] == a[j]) ? 0 : f[j]);

    int from = 2 * n + m, to = 2 * n + m + 1;

    for(int i = 0; i < n + m; ++i)
        mf.add_edge(from, i, 1, 0);

    for(int i = n + m; i < 2 * n + m; ++i)
        mf.add_edge(i, to, 1, 0);

    auto [flow, cost] = mf.get_min_cost_max_flow(from, to);
    static vector<string> code;
    static int previous[2 * k_N + k_M];
    static char letter[2 * k_N + k_M];

    for(int j = 0; j < n + m; ++j){
        for(int edge_index: mf.adjacent[j]){
            Edge edge = mf.edges[edge_index];

            if(edge.capacity && edge.capacity == edge.flow)
                previous[edge.to - n - m] = edge.from;
        }
    }

    for(int i = 0; i < n; ++i){
        if(previous[i] < m){
            letter[i] = 'a' + previous[i];
            code.push_back(string(1, letter[i]) + "=" + to_string(a[i]));
        }
        else{
            letter[i] = letter[previous[i] - m];
            if(a[previous[i] - m] != a[i])
                code.push_back(string(1, letter[i]) + "=" + to_string(a[i]));
        }
        code.push_back("print(" + string(1, letter[i]) + ")");
    }

    cout << code.size() << " " << cost << "\n";
    for(const string &line: code)
        cout << line << "\n";
}