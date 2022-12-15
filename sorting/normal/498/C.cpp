#include <bits/stdc++.h>

using namespace std;

template<size_t k_N>
struct MaxFlow{
    struct Edge{
        int from, to, capacity, flow;
        Edge(){}
        Edge(int from, int to, int capacity, int flow){
            this->from = from;
            this->to = to;
            this->capacity = capacity;
            this->flow = flow;
        }
    };

    static const int k_Inf = 1e9;

    vector<Edge> edges;
    vector<int> adjacent[k_N];
    int n;

    int parent[k_N];
    bool vis[k_N];

    void add_edge(int u, int v, int w){
        edges.push_back({u, v, w, 0});
        edges.push_back({v, u, 0, 0});
        adjacent[u].push_back(edges.size() - 2);
        adjacent[v].push_back(edges.size() - 1);
    }

    void set_n(int n){
        this->n = n;
    }

    int bfs(int start, int end){
        queue<int> st;

        for(int i = 0; i <= n; ++i){
            parent[i] = -1;
            vis[i] = false;
        }

        st.push(start);
        vis[start] = true;

        while(!st.empty()){
            int node = st.front();
            st.pop();

            if(node == end)
                break;

            for(int edge_idx: adjacent[node]){
                auto [from, to, capacity, flow] = edges[edge_idx];
                if(!vis[to] && flow < capacity){
                    vis[to] = true;
                    parent[to] = edge_idx;
                    st.push(to);
                }
            }
        }

        if(!vis[end])
            return 0;

        int node = end, flow = k_Inf;
        while(node != start){
            auto edge = edges[parent[node]];
            flow = min(edge.capacity - edge.flow, flow);
            node = edge.from;
        }

        node = end;
        while(node != start){
            auto &edge = edges[parent[node]];
            auto &rev_edge = edges[parent[node] ^ 1];
            edge.flow += flow;
            rev_edge.flow -= flow;

            node = edge.from;
        }

        return flow;
    }

    int get_max_flow(int start, int end){
        int flow = 0;
        while(true){
            int curr_flow = bfs(start, end);
            if(!curr_flow)
                break;
            flow += curr_flow;
        }
        return flow;
    }
};

const int k_N = 100 + 3;
const int k_Inf = 1e9;

int n, m;
MaxFlow<k_N> max_flow;
int a[k_N];
vector<int> adjacent[k_N];

vector<pair<int, int>> divs[k_N];
int start_node[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        if(b & 1)
            swap(a, b);

        adjacent[a].push_back(b);
    }

    int cnt_nodes = 2;
    for(int i = 1; i <= n; ++i){
        start_node[i] = cnt_nodes;

        int num = a[i];
        for(int d = 2; d * d <= num; ++d){
            if(num % d == 0){
                int cnt = 0;
                while(num % d == 0){
                    num /= d;
                    cnt++;
                }

                divs[i].push_back({d, cnt});
            }
        }

        if(num != 1)
            divs[i].push_back({num, 1});

        cnt_nodes += divs[i].size();

        if(i & 1){
            for(int j = 0; j < divs[i].size(); ++j)
                max_flow.add_edge(0, start_node[i] + j, divs[i][j].second);
        }
        else{
            for(int j = 0; j < divs[i].size(); ++j)
                max_flow.add_edge(start_node[i] + j, 1, divs[i][j].second);
        }
    }

    for(int node1 = 1; node1 <= n; ++node1){
        for(int node2: adjacent[node1]){
            int ptr1 = 0, ptr2 = 0;
            while(ptr1 != divs[node1].size() && ptr2 != divs[node2].size()){
                int d1 = divs[node1][ptr1].first;
                int d2 = divs[node2][ptr2].first;
                if(d1 == d2){
                    max_flow.add_edge(start_node[node1] + ptr1, start_node[node2] + ptr2, k_Inf);
                    ptr1++;
                    ptr2++;
                    continue;
                }

                if(d1 < d2)
                    ptr1++;
                else
                    ptr2++;
            }
        }
    }

    max_flow.n = cnt_nodes;

    cout << max_flow.get_max_flow(0, 1) << "\n";
}