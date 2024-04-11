#include <bits/stdc++.h>
using namespace std;
#define M 10010
typedef long long ll;
const ll inf = 1ll << 60;

int n;
int m;
int x[M];
int L[M], R[M];
ll t[M], s[M];
ll ff[M], gg[M], *f, *g;

int Find(int p) {
    return lower_bound(x, x + m, p) - x;
}

int main() {
    //freopen("F.in", "r", stdin);
    //freopen("F.out", "w", stdout);
    int pos;
    scanf("%d %d", &n, &pos);
    m = 1;
    x[0] = pos;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &L[i], &R[i]);
        x[m++] = L[i];
        x[m++] = R[i];
    }
    sort(x, x + m);
    m = unique(x, x + m) - x;
    pos = Find(pos);

    /*for (int i = 0; i < m; i++) {
        printf("%d ", x[i]);
    }
    puts("");
    printf("pos = %d\n", pos);

    puts("T");
    printf("m = %d\n", m);*/
    f = ff, g = gg;
    for (int i = 0; i < m; i++) {
        f[i] = inf;
    }
    f[pos] = 0;
    //printf("n = %d, m = %d\n", n, m);
    for (int p = 0; p < n; p++) {
        t[m-1] = f[m-1] + x[m-1];
        for (int i = m - 2; i >= 0; i--) {
            t[i] = min(t[i+1], f[i] + x[i]);
        }
        s[0] = f[0] - x[0];
        for (int i = 1; i < m; i++) {
            s[i] = min(s[i-1], f[i] - x[i]);
        }
        int l = Find(L[p]);
        int r = Find(R[p]);
        //printf("l = %d, r = %d\n", l, r);
        for (int i = 0; i < m; i++) {
            g[i] = min(s[i] + x[i], t[i] - x[i]);
            if (r < i) g[i] += x[i] - x[r];
            else if (i < l) g[i] += x[l] - x[i];
            if (g[i] > inf) g[i] = inf;
        }
        swap(f, g);
        /*for (int i = 0; i < m; i++) {
            printf("%d ", f[i]);
        }
        puts("");*/
    }

    printf("%I64d\n", *min_element(f, f + m));
    return 0;
}