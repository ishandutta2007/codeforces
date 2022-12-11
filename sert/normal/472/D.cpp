#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

typedef int ll;
typedef long double ld;
#define ff first
#define ss second
const ll N = 2034;

int n, a[N][N], d[N][N], kol;
int p[N], sz[N], pr[N], vp[N];
pair <int, int> e[N * N];
vector <int> es[N], we[N];

int fnd(int v) {
    return (p[v] == v ? v : p[v] = fnd(p[v]));
}

void uniq(int v1, int v2, int w) {
    if (fnd(v1) == fnd(v2)) return;
    kol++;
    //cerr << v1 << " " << v2 << "\n";
    es[v1].push_back(v2);
    es[v2].push_back(v1);
    we[v1].push_back(w);
    we[v2].push_back(w);
    v1 = fnd(v1);
    v2 = fnd(v2);
    if (sz[v1] == sz[v2]) sz[v1]++;
    if (sz[v1] > sz[v2])
        p[v2] = v1;
    else
        p[v1] = v2;
}

void dfs(int v, int p, int w) {
    pr[v] = p;
    vp[v] = w;
    for (int i = 0; i < es[v].size(); i++)
        if (es[v][i] != p)
            dfs(es[v][i], v, we[v][i]);
}

int getd(int v1, int v2) {
    if (v1 == v2) return 0;
    if (d[v1][v2] != 0) return d[v1][v2];
    if (v1 == 0) d[v1][v2] = d[v2][v1] = vp[v2] + getd(v1, pr[v2]);
    else if (v2 == 0) d[v1][v2] = d[v2][v1] = vp[v1] + getd(pr[v1], v2);
    else d[v1][v2] = d[v2][v1] = min(vp[v1] + getd(pr[v1], v2), vp[v2] + getd(v1, pr[v2]));
    return d[v1][v2];
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            e[i * n + j] = make_pair(a[i][j], i * n + j);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != a[j][i] || (i != j && a[i][j] == 0)) {
                cout << "NO\n";
                return 0;
            }
    for (int i = 0; i < n; i++)
        if (a[i][i]) {
            cout << "NO\n";
            return 0;
        }
    for (int i = 0; i < n; i++)
        p[i] = i;
    sort(e, e + n * n);
    for (int i = 0; i < n * n; i++)
        uniq(e[i].ss / n, e[i].ss % n, e[i].ff);

    dfs(0, 0, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = getd(i, j);

   // for (int i = 0; i < n; cout << "\n", i++)
    //    for (int j = 0; j < n; cout << d[i][j++]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != d[i][j]) {
                cout << "NO\n";
                return 0;
            }
    cout << "YES\n";
    return 0;
}