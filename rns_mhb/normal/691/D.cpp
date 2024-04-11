#include <bits/stdc++.h>
using namespace std;

#define N 1000005

int n, m, cnt;
int p[N], clr[N], ans[N];
vector<int> v[N];
vector<int> w[N];
int tmp[N], top;

void dfs(int x) {
    clr[x] = cnt;
    for (int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if (!clr[y]) dfs(y);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &p[i]);
    }
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i ++) if (!clr[i]) {
        cnt ++;
        dfs(i);
    }
    for (int i = 1; i <= n; i ++) w[clr[i]].push_back(i);
    for (int i = 1; i <= cnt; i ++) {
        top = 0;
        for (int j = 0; j < w[i].size(); j ++) {
            tmp[top++] = p[w[i][j]];
        }
        sort(tmp, tmp + top, greater<int>());
        for (int j = 0; j < w[i].size(); j ++) {
            ans[w[i][j]] = tmp[j];
        }
    }
    for (int i = 1; i <= n; i ++) printf("%d ", ans[i]);
    return 0;
}