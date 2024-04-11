#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) {auto tmp = a; a = b, b = tmp;}

const int N = (int) 2e5 + 500;

int n, q;
int a[N], b[N], pos[N];
vector<int> vals[N], f[N];
int tmp[N];

struct query {
    int la, ra, lb, rb, t;

    query() {}

    void scale() { la--, ra--, lb--, rb--; }
} qry[N];

void addupd(int x, int y) {
    for (int i = x; i < N; i |= i + 1) vals[i].push_back(y);
}

void addget(int x, int y) {
    if (x < 0 || y < 0) return;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) vals[i].push_back(y);
}

void upd(int x, int y, int v) {
    for (int i = x; i < N; i |= i + 1) {
        for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin();
             j < (int) f[i].size(); j |= j + 1) {
            f[i][j] += v;
        }
    }
}

int get(int x, int y) {
    if (x < 0 || y < 0) return 0;
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin(); j >= 0;
             j = (j & (j + 1)) - 1)
            res += f[i][j];
    return res;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        b[i]--;
        b[i] = pos[b[i]];
        tmp[i] = b[i];
    }
    for (int i = 0; i < n; i++) addupd(i, b[i]);
    for (int i = 0; i < q; i++) {
        scanf("%d", &qry[i].t);
        if (qry[i].t == 1) {
            scanf("%d%d%d%d", &qry[i].la, &qry[i].ra, &qry[i].lb, &qry[i].rb);
            qry[i].scale();
            addget(qry[i].rb, qry[i].ra);
            addget(qry[i].rb, qry[i].la - 1);
            addget(qry[i].lb - 1, qry[i].ra);
            addget(qry[i].lb - 1, qry[i].la - 1);
        } else {
            scanf("%d%d", &qry[i].lb, &qry[i].rb);
            qry[i].scale();
            addupd(qry[i].lb, b[qry[i].lb]);
            addupd(qry[i].rb, b[qry[i].rb]);
            swap(b[qry[i].lb], b[qry[i].rb]);
            addupd(qry[i].lb, b[qry[i].lb]);
            addupd(qry[i].rb, b[qry[i].rb]);
        }
    }
    for (int i = 0; i < n; i++) b[i] = tmp[i];

    for (int i = 0; i < n; i++) {
        sort(vals[i].begin(), vals[i].end());
        vals[i].resize(unique(vals[i].begin(), vals[i].end()) - vals[i].begin());
        f[i].resize(vals[i].size(), 0);
    }

    for (int i = 0; i < n; i++) upd(i, b[i], 1);
    for (int i = 0; i < q; i++) {
        if (qry[i].t == 1) {
            int res = 0;
            res += get(qry[i].rb, qry[i].ra);
            res -= get(qry[i].rb, qry[i].la - 1);
            res -= get(qry[i].lb - 1, qry[i].ra);
            res += get(qry[i].lb - 1, qry[i].la - 1);
            printf("%d\n", res);
        } else {
            upd(qry[i].lb, b[qry[i].lb], -1);
            upd(qry[i].rb, b[qry[i].rb], -1);
            swap(b[qry[i].lb], b[qry[i].rb]);
            upd(qry[i].lb, b[qry[i].lb], 1);
            upd(qry[i].rb, b[qry[i].rb], 1);
        }
    }

}