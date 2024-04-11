#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 4e6 + 34;
const ld EPS = 1e-4;

int p1[N], p2[N], a[N];

void build(int v, int l, int r) {
    if (l + 1 == r) {
        p1[v] = l;
        return;
    }
    build(v * 2 + 1, l, (l + r) / 2);
    build(v * 2 + 2, (l + r) / 2, r);
    p1[v] = p1[v * 2 + 1];
    if (p2[v * 2 + 1] != -1) p2[v] = p2[v * 2 + 1];
    else if (p1[v * 2 + 2] != -1 && a[p1[v * 2 + 2]] != a[p1[v]]) p2[v] = p1[v * 2 + 2];
    else if (p2[v * 2 + 2] != -1 && a[p2[v * 2 + 2]] != a[p1[v]]) p2[v] = p2[v * 2 + 2];
}

int solve(int v, int l, int r, int L, int R, int x) {
    if (L >= r || l >= R) return -1;
    if (L <= l && r <= R) {
        if (p1[v] != -1 && a[p1[v]] != x) return 1 + p1[v];
        if (p2[v] != -1 && a[p2[v]] != x) return 1 + p2[v];
        return -1;
    }
    int m = (l + r) / 2;
    return max(solve(v * 2 + 1, l, m, L, R, x), solve(v * 2 + 2, m, r, L, R, x));
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    for (int i = 0; i < N; i++)
        p1[i] = p2[i] = -1;
    int n, m, l, r, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    build(0, 0, n);
    while (m--) {
        scanf("%d%d%d", &l, &r, &x);
        printf("%d\n", solve(0, 0, n, l - 1, r, x));
    }


    return 0;
}