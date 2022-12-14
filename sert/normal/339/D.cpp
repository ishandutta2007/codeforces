#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 34;

int t[N];

void add(int v, int l, int r, int p, int lv, int x) {
    if (l + 1 == r) {
        t[v] = x;
        return;
    }
    // cout << l << " " << r << " " << lv << "\n";
    int m = (l + r) / 2;
    if (p < m)
        add(v * 2 + 1, l, m, p, lv - 1, x);
    else
        add(v * 2 + 2, m, r, p, lv - 1, x);

    if (lv % 2)
        t[v] = (t[v * 2 + 1] | t[v * 2 + 2]);
    else
        t[v] = (t[v * 2 + 1] ^ t[v * 2 + 2]);
}

int get(int v, int l, int r, int L, int R, int lv) {
    if (l >= R || L >= r)
        return 0;
    if (L <= l && r <= R)
        return t[v];
    int m = (l + r) / 2;
    if (lv % 2)
        return get(v * 2 + 1, l, m, L, R, lv - 1) | get(v * 2 + 2, m, r, L, R, lv - 1);
    else
        return get(v * 2 + 1, l, m, L, R, lv - 1) ^ get(v * 2 + 2, m, r, L, R, lv - 1);
}

int n, ln, m, x, p;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%d%d", &ln, &m);
    n = (1 << ln);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        add(0, 0, n, i, ln, x);
    }
    // for (int i = 0; i < 2 * n - 1; i++) printf("%d ", t[i]); printf("\n");
    // printf("%d\n", t[0]);
    while (m --> 0) {
        scanf("%d%d", &p, &x);
        add(0, 0, n, p - 1, ln, x);
        printf("%d\n", t[0]);
    }
}