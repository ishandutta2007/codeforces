#include <bits/stdc++.h>
using namespace std;

#define N 1005

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
typedef long long ll;
int n;
int x[N], y[N], t[N];
double p[N];
vector<int> v[N];
int ver[N], timp;
bool vis[N];

ll sqr(int x) { return 1ll * x * x; }

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    for (int i = 0; i < v[x].size(); i ++) {
        dfs(v[x][i]);
    }
    ver[timp--] = x;
}

double ans;
double dp[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d %d %lf", &x[i], &y[i], &t[i], &p[i]);
    }
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++) if (i != j) {
        if (t[j] < t[i]) continue;
        if (sqr(t[j] - t[i]) >= sqr(x[i] - x[j]) + sqr(y[i] - y[j])) v[i].push_back(j);
    }
    timp = n;
    for (int i = 1; i <= n; i ++) if (!vis[i]) dfs(i);
    for (int i = n; i; i --) {
        dp[ver[i]] = p[ver[i]];
        for (int j = 0; j < v[ver[i]].size(); j ++) {
            int x = v[ver[i]][j];
            chkmax(dp[ver[i]], dp[x] + p[ver[i]]);
        }
        chkmax(ans, dp[ver[i]]);
    }
    printf("%.12lf\n", ans);
    return 0;
}