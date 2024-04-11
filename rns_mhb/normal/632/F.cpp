#include <bits/stdc++.h>
using namespace std;

#define N 2505

int n, m;
int id[N*N], uu[N*N], vv[N*N], ww[N*N];
int a[N][N];
int rt[N];
int d[N];
vector<int> v[N], w[N];

int find_rt(int h) { return h == rt[h] ? h : rt[h] = find_rt(rt[h]); }
bool cmp(int x, int y) { return ww[x] < ww[y]; }

void dfs(int x, int par = 0) {
    for (int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i], z = w[x][i];
        if (y == par) continue;
        d[y] = max(d[x], z);
        dfs(y, x);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            if (i == j) {
                if (a[i][j]) {
                    printf("NOT MAGIC\n");
                    return 0;
                }
            }
            else {
                if (a[i][j] != a[j][i]) {
                    printf("NOT MAGIC\n");
                    return 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++)
    for (int j = i + 1; j <= n; j ++) {
        id[m] = m;
        uu[m] = i, vv[m] = j, ww[m++] = a[i][j];
    }
    sort(id, id + m, cmp);
    for (int i = 1; i <= n; i ++) rt[i] = i;
    for (int i = 0; i < m; i ++) {
        int x = uu[id[i]], y = vv[id[i]];
        x = find_rt(x), y = find_rt(y);
        if (x == y) continue;
        rt[x] = y;
        v[x].push_back(y), w[x].push_back(ww[id[i]]);
        v[y].push_back(x), w[y].push_back(ww[id[i]]);
    }
    for (int i = 1; i <= n; i ++) {
        d[i] = 0;
        dfs(i);
        for (int j = 1; j <= n; j ++) {
            if (d[j] < a[i][j]) {
                printf("NOT MAGIC\n");
                return 0;
            }
        }
    }
    printf("MAGIC\n");
    return 0;
}