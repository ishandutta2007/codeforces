#include <bits/stdc++.h>

using namespace std;

template<class t_Type, size_t t_Size>
class Fenwick_Tree{
private:
    t_Type nodes[t_Size + 1];
    int n;
public:
    Fenwick_Tree(){}
    void set_size(int n){
        this->n = n;
    }
    void update(int idx, t_Type value){
        for(; idx <= t_Size; idx += idx & -idx)
            nodes[idx] += value;
    }
    t_Type query(int idx){
        t_Type answer = 0;
        for(; idx >= 1; idx -= idx & -idx)
            answer += nodes[idx];

        return answer;
    }
    t_Type query(int l, int r){
        return query(r) - query(l - 1);
    }
};

const int k_N = 1e5 + 3;

int n;
long long k;

int a[k_N];

Fenwick_Tree<long long, k_N> left_part, right_part;
map<int, int> index;

long long get_count_inversions_of_position(int position){
    long long answer = 0;

    answer += left_part.query(index[a[position]] + 1, n);
    answer += right_part.query(index[a[position]] - 1);

    return answer;
}

void build_index(){
    static set<int> set_a;

    for(int i = 1; i <= n; ++i)
        set_a.insert(a[i]);

    int cnt = 0;
    for(int x: set_a)
        index[x] = ++cnt;
}

void read_input(){
    cin >> n >> k;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    read_input();
    build_index();

    left_part.set_size(n);
    right_part.set_size(n);

    long long answer = 0, inversions_cnt = 0;
    int ptr = 1;
    for(int i = 1; i <= n; ++i){
        inversions_cnt += right_part.query(index[a[i]] + 1, n);
        right_part.update(index[a[i]], 1);
    }

    for(int i = 1; i <= n; ++i){
        if(ptr == i){
            right_part.update(index[a[ptr]], -1);

            inversions_cnt -= get_count_inversions_of_position(ptr);
            ++ptr;
        }

        left_part.update(index[a[i]], 1);
        inversions_cnt += get_count_inversions_of_position(i);

        while(ptr <= n && inversions_cnt > k){
            right_part.update(index[a[ptr]], -1);

            inversions_cnt -= get_count_inversions_of_position(ptr);
            ++ptr;
        }

        answer += (n - ptr + 1);
    }

    cout << answer << "\n";
}