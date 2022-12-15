#include <bits/stdc++.h>

using namespace std;

template<size_t t_Size>
class Disjoint_Set_Union{
private:
    int parent[t_Size], subtree_size[t_Size];
    int n;
private:
    int get_parent(int node){
        if(parent[node] == node)
            return node;

        return parent[node] = get_parent(parent[node]);
    }
public:
    Disjoint_Set_Union(){}

    void resize(int n){
        this->n = n;

        for(int i = 1; i <= n; ++i){
            parent[i] = i;
            subtree_size[i] = 1;
        }
    }

    bool unite(int node_1, int node_2){
        int parent_1 = get_parent(node_1);
        int parent_2 = get_parent(node_2);

        if(parent_1 == parent_2)
            return false;

        if(subtree_size[parent_1] < subtree_size[parent_2]){
            swap(node_1, node_2);
            swap(parent_1, parent_2);
        }

        subtree_size[parent_1] += subtree_size[parent_2];
        parent[parent_2] = parent_1;

        return true;
    }
};

const int k_N = 1e5 + 3;
const long long k_Inf = 1e18;

int n, m;
array<long long, 3> edges[k_N];
vector<pair<int, int>> adjacent[k_N];

int k;
int portals[k_N];

long long distance[k_N];
int closest_portal[k_N];

Disjoint_Set_Union<k_N> dsu;

void dijkstra(){
    static priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for(int i = 1; i <= n; ++i)
        ::distance[i] = k_Inf;

    for(int i = 0; i < k; ++i){
        const int &portal = portals[i];
        ::distance[portal] = 0;
        pq.push({0, portal});
        closest_portal[portal] = portal;
    }

    while(!pq.empty()){
        auto [node_distance, node] = pq.top();
        pq.pop();

        if(node_distance > ::distance[node])
            continue;

        for(auto [to, weight]: adjacent[node]){
            long long new_distance = ::distance[node] + weight;
            if(new_distance < ::distance[to]){
                ::distance[to] = new_distance;
                closest_portal[to] = closest_portal[node];
                pq.push({::distance[to], to});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < 3; ++j)
            cin >> edges[i][j];

        adjacent[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adjacent[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    cin >> k;
    for(int i = 0; i < k; ++i)
        cin >> portals[i];

    dijkstra();

    for(int i = 0; i < m; ++i){
        auto &edge = edges[i];

        edge[2] += ::distance[edge[0]] + ::distance[edge[1]];
        edge[0] = closest_portal[edge[0]];
        edge[1] = closest_portal[edge[1]];
    }

    sort(edges, edges + m, [](const auto &lvalue, const auto &rvalue){
        return lvalue[2] < rvalue[2];
    });

    long long answer = 0;
    dsu.resize(n);

    for(int i = 0; i < m; ++i){
        const auto &edge = edges[i];

        if(dsu.unite(edge[0], edge[1]))
            answer += edge[2];
    }

    answer += ::distance[1];

    cout << answer << "\n";
}