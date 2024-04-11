#include <bits/stdc++.h>

using namespace std;

template<size_t k_N>
class Min_Cost_Flow{
private:
    struct Edge{
        long long from, to, capacity, cost;

        Edge(){}
        Edge(long long from, long long to, long long capacity, long long cost){
            this->from = from;
            this->to = to;
            this->capacity = capacity;
            this->cost = cost;
        }
    };

    const static long long k_Inf = 1e18;
    long long n;
    vector<long long> adjacent[k_N];
    vector<Edge>edges;
    long long parent[k_N];

    pair<long long, long long> spfa(long long source, long long sink){
        static long long distance[k_N], flow[k_N];
        static bool in_queue[k_N];

        for(long long i = 0; i < n; ++i){
            distance[i] = k_Inf;
            in_queue[i] = false;
            flow[i] = 0;
        }

        queue<int> q;
        q.push(source);
        distance[source] = 0;
        flow[source] = k_Inf;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            in_queue[node] = false;

            for(int edge_idx: adjacent[node]){
                auto [from, to, capacity, cost] = edges[edge_idx];

                if(!capacity)
                    continue;

                int new_distance = distance[node] + cost;
                if(new_distance < distance[to]){
                    distance[to] = new_distance;
                    parent[to] = edge_idx ^ 1;
                    flow[to] = min(flow[node], capacity);
 
                    if(!in_queue[to]){
                        q.push(to);
                        in_queue[to] = true;
                    }
                }
            }
        }

        return {flow[sink], distance[sink]};
    }
public:
    Min_Cost_Flow(){
        n = 0;
    }

    void set_n(long long n){
        this->n = n;
    }

    void add_edge(long long u, long long v, long long capacity, long long cost){
        edges.push_back({u, v, capacity, cost});
        edges.push_back({v, u, 0, -cost});

        adjacent[u].push_back(edges.size() - 2);
        adjacent[v].push_back(edges.size() - 1);
    }

    long long get_max_flow(long long source, long long sink, long long k){
        long long flow = 0, cost = 0;
        bool continue_loop = true;

        while(continue_loop){
            auto [curr_flow, curr_cost] = spfa(source, sink);

            if(!curr_flow || curr_cost + cost > k)
                break;

            if(curr_flow * curr_cost + cost > k){
                curr_flow = (k - cost) / curr_cost;
                continue_loop = false;
            }

            flow += curr_flow;
            cost += curr_flow * curr_cost;

            long long node = sink;
            while(node != source){
                int edge_idx = parent[node];

                long long rev_edge_idx = edge_idx ^ 1;

                edges[edge_idx].capacity += curr_flow;
                edges[rev_edge_idx].capacity -= curr_flow;

                node = edges[edge_idx].to;
            }
        }

        return flow;
    }
};

const long long k_N = 50 + 3;
const long long k_Inf = 1e18;

Min_Cost_Flow<k_N> min_cost_flow;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    min_cost_flow.set_n(n);

    for(long long i = 0; i < n; ++i){
        for(long long j = 0; j < n; ++j){
            long long capacity;
            cin >> capacity;

            if(!capacity)
                continue;

            min_cost_flow.add_edge(i, j, capacity, 0);
            if(i != j)
                min_cost_flow.add_edge(i, j, k_Inf, 1);
        }
    }

    cout << min_cost_flow.get_max_flow(0, n - 1, k) << "\n";
}