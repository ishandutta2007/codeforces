#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void fmin(T &x, T &y) {if (x > y) swap(x, y);}

struct line{
    int x, ymin, ymax, fl;
    line(int xx = 0, int yi = 0, int ya = 0, int f = 0):
        x(xx), ymin(yi), ymax(ya), fl(f) {}
    bool operator < (const line l) {return x < l.x;}
} l[N*2];

int n, cnt, x[2][N], y[2][N], sto[2*N], tree[8*N], len[16*N];

void modify(int v, int vl, int vr, int l, int r, int k) {
    if (l <= vl && vr <= r) tree[v] += k;
    else {
        int m = (vl + vr) >> 1;
        if (l < m) modify(2 * v, vl, m, l, r, k);
        if (r > m) modify(2 * v + 1, m, vr, l, r, k);
    }
    if (tree[v]) len[v] = sto[vr] - sto[vl];
    else len[v] = len[2*v] + len[2*v+1];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 2; j ++)
            scanf("%d %d", &x[j][i], &y[j][i]);
        if (x[0][i] == x[1][i]) {
            fmin(y[0][i], y[1][i]);
            x[1][i] ++, y[1][i] ++;
        }
        else {
            fmin(x[0][i], x[1][i]);
            x[1][i] ++, y[1][i] ++;
        }
        sto[2*i-1] = y[0][i], sto[2*i] = y[1][i];
    }
    sort(sto + 1, sto + 2 * n + 1);
    cnt = unique(sto + 1, sto + 2 * n + 1) - sto - 1;
    for (int i = 1; i <= n; i ++) {
        int yi = lower_bound(sto + 1, sto + cnt + 1, y[0][i]) - sto;
        int ya = lower_bound(sto + 1, sto + cnt + 1, y[1][i]) - sto;
        l[2*i-1] = line(x[0][i], yi, ya, 1);
        l[2*i] = line(x[1][i], yi, ya, -1);
    }
    sort(l + 1, l + 2 * n + 1);
    ll ans = 0;
    for (int i = 1; i <= 2 * n - 1; i ++) {
        modify(1, 1, cnt, l[i].ymin, l[i].ymax, l[i].fl);
        ans += 1ll * len[1] * (l[i+1].x - l[i].x);
    }
    printf("%I64d\n", ans);

    return 0;
}