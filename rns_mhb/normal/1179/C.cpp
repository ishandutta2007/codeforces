#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct Segment_Tree {
#define lv (v<<1)
#define rv (v<<1|1)

    vector <T> a, add;
    int sz, h;
    T INF = 0;
    void push_up(int v) {
        a[v] = max(a[lv], a[rv]);
    }
    int add_delta(int v, T d) {
        a[v] += d;
        if(v < sz) add[v] += d;
    }
    void push_down(int v) {
        if(add[v]) {
            add_delta(lv, add[v]);
            add_delta(rv, add[v]);
            add[v] = 0;
        }
    }
    void up(int v) {while(v>1) v>>=1, push_up(v);}
    void down(int v) {for(int s = h; s; s--) push_down(v>>s);}
    void build(int n) {
        h = __lg(n) + 1, sz = n;
        a.resize(2*n), add.resize(n);
        for(int i = n; i < 2*n; i ++) a[i] = 0;
        for(int v = n-1; v; v --) a[v] = 0, add[v] = 0;
    }
    void Add(int l, int r, T d) {
        l += sz - 1, r += sz;
        int L = l, R = r;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) add_delta(l ++, d);
            if(r & 1) add_delta(-- r, d);
        }
        down(L), down(R-1);
        up(L), up(R-1);
    }
    T query(int l, int r) {
        l += sz - 1, r += sz;
        down(l), down(r-1);
        T rlt = INF;
        int L = l, R = r;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) rlt = max(rlt, a[l ++]);
            if(r & 1) rlt = max(rlt, a[-- r]);
        }
        return rlt;
    }
#undef lv
#undef rv
};

Segment_Tree <int> T;

#define N 300010

int a[N], b[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int M = 1000001;
    T.build(M);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        T.Add(1, a[i], 1);
    }
    for(int i = 1; i <= m; i ++) {
        scanf("%d", &b[i]);
        T.Add(1, b[i], -1);
    }
    int q;
    scanf("%d", &q);
    while(q --) {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        if(type == 1) {
            T.Add(1, a[x], -1);
            a[x] = y;
            T.Add(1, a[x], 1);
        }
        else {
            T.Add(1, b[x], 1);
            b[x] = y;
            T.Add(1, b[x], -1);
        }
        int L = 1, R = M;
        while(L < R) {
            int mid = L + R >> 1;
            if(T.query(mid, M) > 0) L = mid + 1;
            else R = mid;
        }
        R --;
        if(R == 0) R --;
        printf("%d\n", R);
    }
}