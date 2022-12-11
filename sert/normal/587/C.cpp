#include <bits/stdc++.h>

using namespace std;

typedef int ll;
const int N = 1e5 + 7;

struct MS {
    int v, n;
    int a[10];
};

ll n, v1, v2;
MS up[N][18], res, res2;
vector <int> es[N], lst[N];
ll ti[N], to[N], tme;
ll p[N], m, q, a, sz;

void merge1(const vector <int> &a, const vector <int> &b, MS &c) {
    int ca = 0;
    int cb = 0;
    int cc = 0;
    while ((ca < int(a.size()) || cb < int(b.size())) && cc < 10) {
        if (ca < int(a.size()) && cb < int(b.size()))
            if (a[ca] == b[cb])
                ca++;
        if (ca == int(a.size()) || (cb < int(b.size()) && b[cb] < a[ca]))
            c.a[cc++] = b[cb++];
        else
            c.a[cc++] = a[ca++];
    }
    c.n = cc;
}

void merge3(const MS &a, const vector <int> &b, MS &c) {
    int ca = 0;
    int cb = 0;
    int cc = 0;
    while ((ca < a.n || cb < int(b.size())) && cc < 10) {
        if (ca < a.n && cb < int(b.size()))
            if (a.a[ca] == b[cb])
                ca++;
        if (ca == a.n || (cb < int(b.size()) && b[cb] < a.a[ca]))
            c.a[cc++] = b[cb++];
        else
            c.a[cc++] = a.a[ca++];
    }
    c.n = cc;
}

void merge2(const MS &a, const MS &b, MS &c) {
    int ca = 0;
    int cb = 0;
    int cc = 0;
    while ((ca < a.n || cb < b.n) && cc < 10) {
        if (ca < a.n && cb < b.n)
            if (a.a[ca] == b.a[cb])
                ca++;
        if (ca == a.n || (cb < b.n && b.a[cb] < a.a[ca]))
            c.a[cc++] = b.a[cb++];
        else
            c.a[cc++] = a.a[ca++];
    }
    c.n = cc;
}

void dfs(int v, int pr) {
    p[v] = pr;
    ti[v] = tme++;
    for (int i = 0; i < int(es[v].size()); i++)
        if (es[v][i] != pr)
            dfs(es[v][i], v);
    to[v] = tme++;
}

bool is_pr(int v1, int v2) {
    return (ti[v1] <= ti[v2] && to[v1] >= to[v2]);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &v1);
        lst[v1 - 1].push_back(i + 1);
    }
    for (int i = 0; i < n; i++)
        sort(lst[i].begin(), lst[i].end());

    dfs(0, 0);

    for (int i = 0; i < n; i++) {
        up[i][0].v = p[i];
        merge1(lst[i], lst[p[i]], up[i][0]);
    }

    for (int i = 1; i < 18; i++)
        for (int j = 0; j < n; j++) {
            v1 = up[j][i - 1].v;
            up[j][i].v = up[v1][i - 1].v;
            merge2(up[j][i - 1], up[v1][i - 1], up[j][i]);
        }

    while (q --> 0) {
        scanf("%d%d%d", &v1, &v2, &a);
        v1--;
        v2--;
        if (v1 == v2) {
            sz = lst[v1].size();
            sz = min(sz, a);
            printf("%d", sz);
            for (int i = 0; i < sz; i++)
                printf(" %d", lst[v1][i]);
            printf("\n");
            continue;
        }

        merge1(lst[v1], lst[v2], res);

        for (int i = 17; i >= 0; i--)
            if (!is_pr(up[v2][i].v, v1)) {
                merge2(res, up[v2][i], res2);
                res = res2;
                v2 = up[v2][i].v;
            }

        for (int i = 17; i >= 0; i--)
            if (!is_pr(up[v1][i].v, v2)) {
                merge2(res, up[v1][i], res2);
                res = res2;
                v1 = up[v1][i].v;
            }

        if (!is_pr(v1, v2) && !is_pr(v2, v1)) {
            if (p[v1] != p[v2])
                return 1;
            merge3(res, lst[p[v1]], res2);
            res = res2;
        }

        a = min(a, res.n);
        printf("%d", a);
        for (int i = 0; i < a; i++)
            printf(" %d", res.a[i]);
        printf("\n");
    }

    return 0;
}