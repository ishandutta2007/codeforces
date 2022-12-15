#include <bits/stdc++.h>

using namespace std;

template<size_t t_Size>
struct Segment_Tree{
    int tr[4 * t_Size], lazy[4 * t_Size];

    Segment_Tree(){}

    void build(int index, int l, int r, const int &len){
        if(l == r){
            tr[index] = l - len;
            return;
        }

        int mid = (l + r) >> 1;
        build(2 * index + 1, l, mid, len);
        build(2 * index + 2, mid + 1, r, len);

        tr[index] = min(tr[2 * index + 1], tr[2 * index + 2]);
    }

    void push_lazy(int index, int l, int r){
        if(lazy[index]){
            tr[index] += lazy[index];
            if(l != r){
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }
    }

    void update(int index, int l, int r, int sl, int sr, int value){
        push_lazy(index, l, r);

        if(r < sl || l > sr)
            return;
        if(sl <= l && r <= sr){
            lazy[index] = value;
            push_lazy(index, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * index + 1, l, mid, sl, sr, value);
        update(2 * index + 2, mid + 1, r, sl, sr, value);

        tr[index] = min(tr[2 * index + 1], tr[2 * index + 2]);
    }

    int query(int index, int l, int r, int sl, int sr){
        push_lazy(index, l, r);

        if(r < sl || l > sr)
            return 0;
        if(sl <= l && r <= sr)
            return tr[index];

        int mid = (l + r) >> 1;
        int lvalue = query(2 * index + 1, l, mid, sl, sr);
        int rvalue = query(2 * index + 2, mid + 1, r, sl, sr);

        return min(lvalue, rvalue);
    }
};

const int k_N = 15e4 + 3;

int a[k_N], b[k_N];
int n, len, h;

Segment_Tree<k_N> segment_tree;

int get_index(int x){
    return (upper_bound(b, b + len, x) - b) - 1;
}

void solve(){
    for(int i = 0; i < len; ++i)
        b[i] = h - b[i];
    sort(b, b + len);

    segment_tree.build(0, 0, len - 1, len);

    for(int i = 0; i < len; ++i){
        int index = get_index(a[i]);
        if(index != -1)
            segment_tree.update(0, 0, len - 1, 0, index, 1);
    }

    int answer = 0;
    if(segment_tree.tr[0] >= 0)
        answer++;

    for(int i = len; i < n; ++i){
        int index = get_index(a[i]);
        if(index != -1)
            segment_tree.update(0, 0, len - 1, 0, index, 1);

        index = get_index(a[i - len]);
        if(index != -1)
            segment_tree.update(0, 0, len - 1, 0, index, -1);

        if(segment_tree.tr[0] >= 0)
            answer++;
    }

    cout << answer << "\n";
}

void read(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> len >> h;

    for(int i = 0; i < len; ++i)
        cin >> b[i];

    for(int i = 0; i < n; ++i)
        cin >> a[i];
}

int main(){
    read();
    solve();
}