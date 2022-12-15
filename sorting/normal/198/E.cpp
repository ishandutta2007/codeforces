#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")

using std::vector, std::array, std::cin, std::cout, std::map, std::set, std::ios, std::queue, std::pair, std::endl;

const long long k_N = 25e4 + 7;
const long long k_Inf = 1e18 + 7;
 
long long get_distance(long long x1, long long y1, long long x2, long long y2){
    long long d = (long long)(x1 - x2) * (long long)(x1 - x2) + (long long)(y1 - y2) * (long long)(y1 - y2);
    
    long long answer = sqrt(d);
    while(answer * answer < d)
        ++answer;
 
    return answer;
}
 
int x, y, p, r, n;
array<int, 5> grippers[k_N];
long long distance[k_N];
 
vector<long long> values;
map<long long, int> idx;
int cnt_values;
 
template <size_t t_Size>
class Segment_Tree{
private:
    vector<int> v[t_Size];
private:
    int merge(int left_node, int right_node){
        if(left_node == -1 || right_node == -1)
            return (left_node != -1) ? left_node : right_node;
        return (grippers[left_node][2] < grippers[right_node][2]) ? left_node : right_node;
    }
private:
    int nodes[4 * t_Size];
    int n;
 
    void initialise(int index, int l, int r){
        if(l == r){
            v[l].push_back(-1);
            nodes[index] = -1;
            return;
        }
 
        int mid = (l + r) >> 1;
        initialise(2 * index + 1, l, mid);
        initialise(2 * index + 2, mid + 1, r);
 
        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
    }
 
    void add(int index, int l, int r, int s_index, int index_in_array){
        if(s_index < l || r < s_index)
            return;
        if(l == r){
            if(v[l].size() == 1 && nodes[index] == -1)
                v[l].pop_back();
            v[l].push_back(index_in_array);
            nodes[index] = index_in_array;
            return;
        }
 
        int mid = (l + r) >> 1;
        add(2 * index + 1, l, mid, s_index, index_in_array);
        add(2 * index + 2, mid + 1, r, s_index, index_in_array);
 
        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
    }
 
    void remove(int index, int l, int r, int s_index){
        if(s_index < l || r < s_index)
            return;
        if(l == r){
            if(v[l].size() != 1)
                v[l].pop_back();
            else
                v[l].back() = -1;
 
            nodes[index] = v[l].back();
            return;
        }
 
        int mid = (l + r) >> 1;
        remove(2 * index + 1, l, mid, s_index);
        remove(2 * index + 2, mid + 1, r, s_index);
 
        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
    }
 
    int query(int index, int l, int r, int sl, int sr){
        if(sl > r || l > sr)
            return -1;
        if(sl <= l && r <= sr)
            return nodes[index];
 
        int mid = (l + r) >> 1;
        int left_value = query(2 * index + 1, l, mid, sl, sr);
        int right_value = query(2 * index + 2, mid + 1, r, sl, sr);
 
        return merge(left_value, right_value);
    }
public:
    Segment_Tree(){}
    void resize(int n){
        this->n = n;
        initialise(0, 0, n - 1);
    }
    void add(int s_index, int index_in_array){
        add(0, 0, n - 1, s_index, index_in_array);
    }
    void remove(int s_index){
        remove(0, 0, n - 1, s_index);
    }
    
    int query(int l, int r){
        return query(0, 0, n - 1, l, r);
    }
};
 
Segment_Tree<2 * k_N> st;
 
void compress_values(){
    static set<long long> s;
    for(long long value: values)
        s.insert(value);
 
    cnt_values = 0;
    for(long long value: s)
        idx[value] = cnt_values++;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> x >> y >> p >> r >> n;
 
    values.push_back(r);
    for(long long i = 0; i < n; ++i){
        for(long long j = 0; j < 5; ++j)
            cin >> grippers[i][j];
 
        distance[i] = get_distance(x, y, grippers[i][0], grippers[i][1]);
 
        values.push_back(grippers[i][4]);
        values.push_back(distance[i]);
    }
 
    compress_values();
 
    queue<array<int, 2>> q;
    q.push({p, r});
 
    static vector<long long> permutation(n);
    for(long long i = 0; i < n; ++i)
        permutation[i] = i;
 
    sort(permutation.begin(), permutation.end(), [](long long lvalue, long long rvalue){
        return grippers[lvalue][2] > grippers[rvalue][2];
    });
 
    st.resize(cnt_values);
    for(long long i: permutation)
        st.add(idx[distance[i]], i);
 
    int answer = -1;
    while(!q.empty()){
        auto [p, r] = q.front();
        q.pop();
        ++answer;
 
        int idx_r = idx[r];
 
        while(true){
            int index_in_array = st.query(0, idx_r);
 
            if(index_in_array == -1 || grippers[index_in_array][2] > p)
                break;
 
            auto &gripper = grippers[index_in_array];
            q.push(array<int, 2>{gripper[3], gripper[4]});
            st.remove( idx[distance[index_in_array]] );
        }
    }
 
    cout << answer << "\n";
}