#include <bits/stdc++.h>

using namespace std;

template<size_t k_N>
struct Segment_Tree{
    int nodes[4 * k_N], lazy[4 * k_N];
    static const int k_Inf = 2e9 + 7;

    Segment_Tree(){
        for(int i = 0; i < 4 * k_N; ++i){
            nodes[i] = 0;
            lazy[i] = 0;
        }
    }

    void push_lazy(int index, int l, int r){
        if(lazy[index]){
            if(l != r){
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            nodes[index] += lazy[index];
            lazy[index] = 0;
        }
    }

    void update(int index, int l, int r, int sl, int sr, int diff){
        if(sl > sr)
            return;
        push_lazy(index, l, r);

        if(sl > r || sr < l)
            return;
        if(sl <= l && r <= sr){
            lazy[index] += diff;
            push_lazy(index, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * index + 1, l, mid, sl, sr, diff);
        update(2 * index + 2, mid + 1, r, sl, sr, diff);

        nodes[index] = max(nodes[2 * index + 1], nodes[2 * index + 2]);
    }

    int query(int index, int l, int r, int sl, int sr){
        push_lazy(index, l, r);
        if(sl > r || sr < l)
            return -k_Inf;
        if(sl <= l && r <= sr)
            return nodes[index];

        int mid = (l + r) >> 1;

        int lvalue = query(2 * index + 1, l, mid, sl, sr);
        int rvalue = query(2 * index + 2, mid + 1, r, sl, sr);

        return max(lvalue, rvalue);
    }
};

const int k_N = 2e5 + 7;
const int k_Max = 1e6 + 7;
const int k_Inf = 2e9 + 7;

int n, m, p;
array<int, 2> a[k_N], b[k_N];
array<int, 3> c[k_N];

vector<int> va[k_Max];
vector<pair<int, int>> vc[k_Max];

Segment_Tree<k_N> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;

    for(int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    for(int i = 0; i < m; ++i)
        cin >> b[i][0] >> b[i][1];
    for(int i = 0; i < p; ++i)
        cin >> c[i][0] >> c[i][1] >> c[i][2];

    sort(b, b + m);

    for(int i = 0; i < n; ++i)
        va[a[i][0]].push_back(a[i][1]);
    for(int i = 0; i < p; ++i)
        vc[c[i][0]].push_back({c[i][1], c[i][2]});


    for(int i = 0; i < m; ++i)
        st.update(0, 0, m - 1, i, i, -b[i][1]);

    int answer = -k_Inf;
    for(int i = 0; i < k_Max; ++i){
        for(int x: va[i])
            answer = max(st.query(0, 0, m - 1, 0, m - 1) - x, answer);

        for(auto [first, second]: vc[i]){
            int index = upper_bound(b, b + m, array{first, k_Inf}) - b;
            st.update(0, 0, m - 1, index, m - 1, second);
        }
    }

    cout << answer << "\n";
}