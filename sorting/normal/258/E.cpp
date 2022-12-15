#include <bits/stdc++.h>

//using namespace std;
using std::vector, std::cout, std::cin, std::endl;

template<size_t t_Size>
class Segment_Tree{
private:
    struct Node{
        int min, count;

        Node(){}
        Node(int value){
            min = value;
            count = 1;
        }

        friend Node merge(const Node &lvalue, const Node &rvalue){
            Node answer;

            answer.min = std::min(lvalue.min, rvalue.min);
            answer.count = 0;

            answer.count += (lvalue.min == answer.min) ? lvalue.count : 0;
            answer.count += (rvalue.min == answer.min) ? rvalue.count : 0;

            return answer;
        }
    };
private:
    Node nodes[4 * t_Size];
    int lazy[4 * t_Size];
    int n;
private:
    void intialise(int index, int l, int r){
        if(l == r){
            nodes[index] = 0;
            return;
        }

        int mid = (l + r) >> 1;
        intialise(2 * index + 1, l, mid);
        intialise(2 * index + 2, mid + 1, r);

        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
    }

    void push_lazy(int index, int l, int r){
        if(!lazy[index])
            return;

        if(l != r){
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }

        nodes[index].min += lazy[index];
        lazy[index] = 0;
    }

    void update(int index, int l, int r, int sl, int sr, int value){
        push_lazy(index, l, r);

        if(l > sr || r < sl)
            return;
        if(sl <= l && r <= sr){
            lazy[index] = value;
            push_lazy(index, l, r);
            return;
        }

        int mid = (l + r) >> 1;

        update(2 * index + 1, l, mid, sl, sr, value);
        update(2 * index + 2, mid + 1, r, sl, sr, value);

        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
    }

    int query(int index, int l, int r, int sl, int sr){
        push_lazy(index, l, r);

        if(l > sr || r < sl)
            return 0;
        if(sl <= l && r <= sr){
            if(nodes[index].min)
                return 0;
            return nodes[index].count;
        }

        int mid = (l + r) >> 1;

        int lvalue = query(2 * index + 1, l, mid, sl, sr);
        int rvalue = query(2 * index + 2, mid + 1, r, sl, sr);

        return lvalue + rvalue;
    }
public:
    Segment_Tree(){}

    void resize(int n){
        this->n = n;
        intialise(0, 0, n - 1);
    }

    void add_value_to_range(int l, int r, int value){
        update(0, 0, n - 1, l, r, value);
    }

    int get_count_of_nodes(){
        return n - query(0, 0, n - 1, 0, n - 1);
    }
};

const int k_N = 1e5 + 3;
const int k_M = 1e5 + 3;

int n, m;
vector<int> adjacent[k_N];
vector<int> links[k_N];

vector<int> order;
int begin[k_N], end[k_N];

Segment_Tree<k_N> segment_tree;

int answer[k_N];

void dfs(int node, int parent = -1){

    if(!links[node].empty())
        segment_tree.add_value_to_range(begin[node], end[node], 1);

    for(int to: links[node])
        segment_tree.add_value_to_range(begin[to], end[to], 1);

    segment_tree.add_value_to_range(begin[node], begin[node], 1);
    answer[node] = segment_tree.get_count_of_nodes() - 1;
    segment_tree.add_value_to_range(begin[node], begin[node], -1);

    for(int to: adjacent[node]){
        if(to == parent)
            continue;

        dfs(to, node);
    }

    if(!links[node].empty())
        segment_tree.add_value_to_range(begin[node], end[node], -1);

    for(int to: links[node])
        segment_tree.add_value_to_range(begin[to], end[to], -1);
}

void build_order(int node, int parent = -1){
    order.push_back(node);
    begin[node] = (int)order.size() - 1;

    for(int to: adjacent[node]){
        if(to == parent)
            continue;

        build_order(to, node);
    }

    end[node] = (int)order.size() - 1; 
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        links[a].push_back(b);
        links[b].push_back(a);
    }

    build_order(1);
    segment_tree.resize(n);
    dfs(1);

    for(int i = 1; i <= n; ++i)
        cout << answer[i] << " ";
    cout << "\n"; 
}