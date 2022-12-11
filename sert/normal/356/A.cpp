#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 4e6 + 34;

int t[N], ans[N];

void add(int v, int l, int r, int L, int R, int x) {
    if (l >= R || L >= r) return;
    if (L <= l && r <= R) {
        t[v] = x;
        return;
    }
    if (t[v]) {
        t[v * 2 + 1] = t[v * 2 + 2] = t[v];
        t[v] = 0;
    }
    add(v * 2 + 1, l, (l + r) / 2, L, R, x);
    add(v * 2 + 2, (l + r) / 2, r, L, R, x);
}

void get_ans(int v, int l, int r) {
    if (l + 1 == r) {
        ans[l] = t[v];
        return;
    }
    if (t[v])
        t[v * 2 + 1] = t[v * 2 + 2] = t[v];
    get_ans(v * 2 + 1, l, (l + r) / 2);
    get_ans(v * 2 + 2, (l + r) / 2, r);
}

int l[N], r[N], w[N], n, m;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &l[i], &r[i], &w[i]);

    for (int i = m - 1; i >= 0; i--) {
        add(0, 0, n, l[i] - 1, w[i] - 1, w[i]);
        add(0, 0, n, w[i], r[i], w[i]);
    }

    get_ans(0, 0, n);

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);  

    //return 0;
}