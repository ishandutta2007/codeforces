#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5e5 + 34;
const int M = 20;
const int INF = 1e9 + 34;

int t[N * 5];

void add(int v, int l, int r, int p, int x) {
    if (r - l == 1) {
        t[v] = min(t[v], x);
        return;
    }
    int m = (l + r) / 2;
    if (p < m)
        add(v * 2 + 1, l, m, p, x);
    else
        add(v * 2 + 2, m, r, p, x);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

int get_min(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r)
        return INF;
    if (L <= l && r <= R)
        return t[v];
    int m = (l + r) / 2;
    return min(get_min(v * 2 + 1, l, m, L, R), get_min(v * 2 + 2, m, r, L, R));
}

int cur, up, n, m;
pair <int, int> a[N];
int b[N], lst[N], l, r, c[N], ans[N];
vector <pair<int, int> > es[N];

int main() {
    ///freopen("a.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < N * 5; i++)
        t[i] = INF;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    a[n].first = a[n - 1].first + 34;
    for (int i = 0; i < n; i++) {
        if (a[i].first != a[i + 1].first)
            up = 1;
        else
            up = 0;
        a[i].first = cur;
        cur += up;
        swap(a[i].first, a[i].second);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i].second;
        lst[i] = -1;
        c[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        if (lst[b[i]] != -1)
            c[lst[b[i]]] = i - lst[b[i]];
        lst[b[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        es[l - 1].push_back(make_pair(r, i));
    }

    for (int i = n - 1; i >= 0; i--) {
        if (c[i] != INF)
            add(0, 0, n, i + c[i], c[i]);
        for (int j = 0; j < es[i].size(); j++)
            ans[es[i][j].second] = get_min(0, 0, n, i, es[i][j].first);
    }

    for (int i = 0; i < m; i++)
        if (ans[i] == INF)
            printf("-1\n");
        else
            printf("%d\n", ans[i]);

    return 0;
}