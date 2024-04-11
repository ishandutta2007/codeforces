#include <bits/stdc++.h>
using namespace std;

const int K = 250;

#define N 101010

int n, m, q;
long long a[N];
long long b[N];
long long c[N];

int sz[N];
vector <int> v[N], u[N];

int id[N/K], t;
int val[N/K][N/K];

int e;
char tmp[3];
int k[N], x[N], type[N];

void input_query() {
    e ++;
    scanf("%s", tmp);
    type[e] = (tmp[0] == '+') ? 1 : 2;
    if (type[e] == 1) scanf("%d %d", &k[e], &x[e]);
    else scanf("%d", &k[e]);
}

void calc_b() {
    memset(b, 0, sizeof b);
    for (int i = 1; i <= m; i ++) for (int j = 0; j < sz[i]; j ++) b[i] += a[v[i][j]];
}

int common(int i, int j) {
    if (i == j) return sz[i];
    int k = 0, h = 0;
    int rlt = 0;
    while (1) {
        if (k >= sz[i] || h >= sz[j]) break;
        if (v[i][k] == v[j][h]) rlt ++, k ++, h ++;
        else if (v[i][k] > v[j][h]) h ++;
        else k ++;
    }
    return rlt;
}

bool exist(int x, int j) {
    int i = lower_bound(v[j].begin(), v[j].end(), x) - v[j].begin();
    if (i < sz[j] && v[j][i] == x) return 1;
    return 0;
}

int func(int i, int j) {
    if (i == j) return sz[i];
    if (sz[i] >= K && sz[j] >= K) {
        int ii = lower_bound(id + 1, id + t + 1, i) - id;
        int jj = lower_bound(id + 1, id + t + 1, j) - id;
        return val[ii][jj];
    }
    if (sz[i] > sz[j]) swap(i, j);
    if (sz[j] > 3 * sz[i]) {
        int rlt = 0;
        for (int k = 0; k < sz[i]; k ++) if (exist(v[i][k], j)) rlt ++;
        return rlt;
    }
    else return common(i, j);
}

void solve() {
    for (int r = 1; r <= e; r ++) {
        if (type[r] == 1) {
            c[k[r]] += x[r];
        }
        else {
            long long ans = b[k[r]];
            for (int h = 1; h < r; h ++) if (type[h] == 1) {
                int gas = func(k[r], k[h]);
                ans += 1ll * gas * x[h];
            }
            printf("%I64d\n", ans);
        }
    }
    for (int i = 1; i <= n; i ++) for (int j = 0; j < u[i].size(); j ++) a[i] += c[u[i][j]];
    calc_b();
    e = 0;
    memset(c, 0, sizeof c);
}

int main() {
    //freopen("r.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i ++) scanf("%I64d", &a[i]);
    for (int i = 1; i <= m; i ++) {
        scanf("%d", &sz[i]);
        v[i].resize(sz[i]);
        for (int j = 0; j < sz[i]; j ++) scanf("%d", &v[i][j]), u[v[i][j]].push_back(i);
        sort(v[i].begin(), v[i].end());
        if (sz[i] >= K) id[++t] = i;
    }
    for (int ii = 1, i; ii < t; ii ++) {
        i = id[ii];
        for (int jj = ii + 1, j; jj <= t; jj ++) {
            j = id[jj];
            val[ii][jj] = common(i, j);
            val[jj][ii] = val[ii][jj];
        }
    }
    calc_b();
    for (int k = 1; k <= q; k ++) {
        input_query();
        if (k % K == 0 || k == q) solve();
    }

    return 0;
}