#include <bits/stdc++.h>

using namespace std;

template<size_t t_N>
struct Segment_Tree{
    int nodes[4 * t_N], lazy[4 * t_N];

    Segment_Tree(){}

    void clear(){
        for(int i = 0; i < 4 * t_N; ++i){
            nodes[i] = 0;
            lazy[i] = 0;
        }
    }

    void update_lazy(int index, int l, int r){
        lazy[index] &= 1;
        if(lazy[index]){
            nodes[index] = (r - l + 1) - nodes[index];

            if(l != r){
                lazy[2 * index + 1]++;
                lazy[2 * index + 2]++;
            }

            lazy[index] = 0;
        }
    }

    void update(int index, int l, int r, int sl, int sr){
        update_lazy(index, l, r);

        if(l > sr || r < sl)
            return;
        if(sl <= l && r <= sr){
            lazy[index] = 1;
            update_lazy(index, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * index + 1, l, mid, sl, sr);
        update(2 * index + 2, mid + 1, r, sl, sr);
    
        nodes[index] = nodes[2 * index + 1] + nodes[2 * index + 2];
    } 

    int query(int index, int l, int r, int sl, int sr){
        update_lazy(index, l, r);

        if(l > sr || r < sl)
            return 0;
        if(sl <= l && r <= sr)
            return nodes[index];

        int mid = (l + r) >> 1;

        int l_value = query(2 * index + 1, l, mid, sl, sr);
        int r_value = query(2 * index + 2, mid + 1, r, sl, sr);

        return l_value + r_value;
    }
};

const int k_N = 1e5 + 7;

int n, k;
int cows[k_N];

Segment_Tree<k_N> segment_tree;
vector<pair<int, int>> v[k_N];

int out_degree[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; ++i)
        cin >> cows[i];

    sort(cows, cows + n);

    for(int i = 0; i < k; ++i){
        int start, end;
        cin >> start >> end;

        start = lower_bound(cows, cows + n, start) - cows;
        end = upper_bound(cows, cows + n, end) - 1 - cows;

        v[start].push_back({start, end});
        v[end + 1].push_back({start, end});
    }

    for(int i = 0; i < n; ++i){
        //segment_tree.update(0, 0, n - 1, i, i);
        for(auto [first, second]: v[i])
            segment_tree.update(0, 0, n - 1, first, second);

        out_degree[i] = 0;
        if(i)
            out_degree[i] += i - segment_tree.query(0, 0, n - 1, 0, i - 1);
        if(i != n - 1)
            out_degree[i] += segment_tree.query(0, 0, n - 1, i + 1, n - 1);
    }
        
    long long answer = 0;
    for(int i = 0; i < n; ++i)
        answer += (long long)out_degree[i] * (out_degree[i] - 1) / 2;

    answer = (long long)n * (n - 1) * (n - 2) / 6 - answer;

    cout << answer << "\n";
}