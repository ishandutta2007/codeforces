#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 3e5 + 34;

int n, b[N];
pair<int, int> a[N];
int lst, cur;
int p[N], s[N], ls[N];

int t[N * 8];
int ad[N * 8];

void add(int v, int l, int r, int L, int R, int x) {
    if (l >= R || L >= r) return;
    if (L <= l && r <= R) {
        t[v] |= x;
        return;
    }
    int m = (l + r) / 2;
    add(v * 2 + 1, l, m, L, R, x);
    add(v * 2 + 2, m, r, L, R, x);
}

void push(int v, int l, int r) {
    if (l + 1 == r)
        return;
    int m = (l + r) / 2;
    t[v * 2 + 1] |= t[v];
    t[v * 2 + 2] |= t[v];
    push(v * 2 + 1, l, m);
    push(v * 2 + 2, m, r);
    t[v] = t[v * 2 + 1] & t[v * 2 + 2];
}

int res(int v, int l, int r, int L, int R) {
    if (L >= r || l >= R) return (1 << 30) - 1;
    if (L <= l && r <= R) return t[v];
    int m = (l + r) / 2;
    return (res(v * 2 + 1, l, m, L, R) & res(v * 2 + 2, m, r, L, R));
}

int l[N], r[N], q[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &l[i], &r[i], &q[i]);
        add(0, 0, n, l[i] - 1, r[i], q[i]);
    }
    push(0, 0, n);
    for (int i = 0; i < m; i++)
        if (res(0, 0, n, l[i] - 1, r[i]) != q[i]) {
            //cerr << q[i] << " " << i << " " << res(0, 0, n, l[i] - 1, r[i]) << "\n";
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d ", res(0, 0, n, i, i + 1));



    return 0;
}