#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 7;

class Persistent_Segment_Tree{
private:
    struct Node{
        int max_ones, suffix_ones, prefix_ones;
        int size, index;
        int left_node, right_node;

        Node(){}
        Node(bool value, int index){
            max_ones = suffix_ones = prefix_ones = value;
            left_node = right_node = -1;
            size = 1;
            this->index = index;
        }

        friend Node merge(Node lvalue, Node rvalue, int index){
            Node answer;

            answer.max_ones = max({lvalue.max_ones, rvalue.max_ones, lvalue.suffix_ones + rvalue.prefix_ones});
            answer.prefix_ones = (lvalue.prefix_ones == lvalue.size) ? (lvalue.prefix_ones + rvalue.prefix_ones) : lvalue.prefix_ones;
            answer.suffix_ones = (rvalue.suffix_ones == rvalue.size) ? (rvalue.suffix_ones + lvalue.suffix_ones) : rvalue.suffix_ones;

            answer.index = index;
            answer.size = lvalue.size + rvalue.size;

            answer.left_node = lvalue.index;
            answer.right_node = rvalue.index;

            return answer;
        }
    };
private:
    vector<Node> nodes;
    int n;

    int get_new_node(){
        nodes.push_back({});
        return (int)nodes.size() - 1;
    }

    void initialise(int index, int l, int r){
        if(l == r){
            nodes[index] = Node(true, index);
            return;
        }

        int mid = (l + r) >> 1;

        int left_node = get_new_node();
        initialise(left_node, l, mid);

        int right_node = get_new_node();
        initialise(right_node, mid + 1, r);

        nodes[index] = merge(nodes[left_node], nodes[right_node], index);
    }

    int update(int index, int l, int r, int s, bool new_value){
        if(s < l || r < s)
            return index;
        if(l == r){
            int new_index = get_new_node();
            nodes[new_index] = Node(new_value, new_index);
            return new_index;
        }

        int mid = (l + r) >> 1;

        int left_node = update(nodes[index].left_node, l, mid, s, new_value);
        int right_node = update(nodes[index].right_node, mid + 1, r, s, new_value);

        int new_index = get_new_node();
        nodes[new_index] = merge(nodes[left_node], nodes[right_node], new_index); 

        return new_index;
    }

    Node query(int index, int l, int r, int sl, int sr){
        if(l > sr || r < sl)
            return Node(0, index);
        if(sl <= l && r <= sr)
            return nodes[index];

        int mid = (l + r) >> 1;
        Node lvalue = query(nodes[index].left_node, l, mid, sl, sr);
        Node rvalue = query(nodes[index].right_node, mid + 1, r, sl, sr);

        return merge(lvalue, rvalue, index);
    }
public:
    Persistent_Segment_Tree(){}

    int initialise(int n){
        this->n = n;

        nodes.push_back({});
        initialise(0, 0, n - 1);

        return 0;
    }

    int update(int root, int s, bool new_value){
        return update(root, 0, n - 1, s, new_value);
    }

    int query(int root, int l, int r){
        return query(root, 0, n - 1, l, r).max_ones;
    }
};

int n, m;
int h[k_N], original_value[k_N];
int cnt_values;
array<int, 3> queries[k_N];

Persistent_Segment_Tree pst;
int root[k_N];

void compress_array(){
    static set<int> s;
    static map<int, int> mp;

    for(int i = 0; i < n; ++i)
        s.insert(h[i]);

    cnt_values = 0;
    for(int x: s){
        original_value[cnt_values] = x;
        mp[x] = cnt_values++;
    }

    for(int i = 0; i < n; ++i)
        h[i] = mp[h[i]];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> h[i];

    compress_array();

    cin >> m;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < 3; ++j)
            cin >> queries[i][j];

        queries[i][0]--;
        queries[i][1]--;
    }

    static vector<int> v[k_N];
    for(int i = 0; i < n; ++i)
        v[h[i]].push_back(i);

    root[0] = pst.initialise(n);

    for(int i = 1; i <= cnt_values - 1; ++i){
        root[i] = root[i - 1];
        for(int idx: v[i - 1])
            root[i] = pst.update(root[i], idx, false);
    }

    for(int i = 0; i < m; ++i){
        auto query = queries[i];

        int l = 0, r = cnt_values - 1;
        while(l != r){
            int mid = (l + r + 1) >> 1;

            if(pst.query(root[mid], query[0], query[1]) >= query[2])
                l = mid;
            else
                r = mid - 1;
        }

        cout << original_value[l] << "\n";
    }//
}