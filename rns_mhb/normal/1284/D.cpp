#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct Segment_Tree {
#define lv (v<<1)
#define rv (v<<1|1)

    vector <T> a, add;
    vector <int> len;
    int sz, h;

    void push_up(int v) {
        a[v] = a[lv] + a[rv];
    }
    int add_delta(int v, T d) {
        a[v] += d * len[v];
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
        a.resize(2*n), len.resize(2*n), add.resize(n);
        for(int i = n; i < 2*n; i ++) len[i] = 1, a[i] = 0;
        for(int v = n-1; v; v --) len[v] = len[lv] + len[rv], push_up(v), add[v] = 0;
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
        T rlt = 0;
        int L = l, R = r;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) rlt += a[l ++];
            if(r & 1) rlt += a[-- r];
        }
        return rlt;
    }
#undef lv
#undef rv
};

typedef long long ll;

#define N 400010

vector <int> v[N], q[N];
int n;

bool solve(int *a, int *b, int *c, int *d) {
    for(int i = 0; i < N; i ++) v[i].clear(), q[i].clear();
    for(int i = 1; i <= n; i ++) v[d[i]].push_back(i);
    for(int i = 1; i <= n; i ++) q[c[i]].push_back(i);
    Segment_Tree <ll> T;
    T.build(N);
    for(int i = 1; i < N; i ++) {
        for(int j = 0; j < q[i].size(); j ++) {
            int k = q[i][j];
            ll sum = T.query(a[k], b[k]);
            if(sum > 0) return 0;
        }
        for(int j = 0; j < v[i].size(); j ++) {
            int k = v[i][j];
            T.Add(a[k], b[k], 1);
        }
    }
    return 1;
}

int a[N], b[N], c[N], d[N], e[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    int m = 0;
    for(int i = 1; i <= n; i ++) e[++ m] = a[i], e[++ m] = b[i], e[++ m] = c[i], e[++ m] = d[i];
    sort(e + 1, e + m + 1);
    m = unique(e + 1, e + m + 1) - e - 1;
    for(int i = 1; i <= n; i ++) {
        a[i] = lower_bound(e+1, e+m+1, a[i]) - e;
        b[i] = lower_bound(e+1, e+m+1, b[i]) - e;
        c[i] = lower_bound(e+1, e+m+1, c[i]) - e;
        d[i] = lower_bound(e+1, e+m+1, d[i]) - e;
    }
    if(solve(a, b, c, d) && solve(c, d, a, b)) puts("YES");
    else puts("NO");
}