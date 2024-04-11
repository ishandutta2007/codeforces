#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 4001000
#define M 300010
#define lv (v<<1)
#define rv (v<<1|1)
#define mid (l+r>>1)

int mx[N<<2], add[N<<2];

void build(int v, int l, int r) {
    mx[v] = 0, add[v] = 0;
    if(l == r) return;
    build(lv, l, mid);
    build(rv, mid+1, r);
}

void push_up(int v) {
    mx[v] = max(mx[lv], mx[rv]);
}

void add_delta(int v, int d) {
    mx[v] += d, add[v] += d;
}

void push_down(int v) {
    if(add[v]) {
        add_delta(lv, add[v]);
        add_delta(rv, add[v]);
        add[v] = 0;
    }
}

void update(int v, int l, int r, int L, int R, int d) {
    if(L <= l && r <= R) {
        add_delta(v, d);
        return;
    }
    push_down(v);
    if(L <= mid) update(lv, l, mid, L, R, d);
    if(mid < R) update(rv, mid+1, r, L, R, d);
    push_up(v);
}

pii p[M];

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    r <<= 1;
    for(int i = 1, x, y; i <= n; i ++) {
        scanf("%d%d", &x, &y);
        p[i] = pii(x-y, x+y);
    }
    sort(p + 1, p + n + 1);
    build(1, 1, N-1);
    int K = N>>1, ans = 0;
    for(int i = 1, j = 1; i <= n; i ++) {
        update(1, 1, N-1, p[i].second-r+K, p[i].second+K, 1);
        while(p[j].first < p[i].first - r) update(1, 1, N-1, p[j].second-r+K, p[j].second+K, -1), j ++;
        ans = max(ans, mx[1]);
    }
    cout << ans << endl;
}