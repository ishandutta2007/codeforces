#include <bits/stdc++.h>
using namespace std;

#define N 100005

const int INF = 1e9 + 7;
int n, rt;
int val[N], pa[N], son[N][2];
int ans;

multiset<int> lebnd, ribnd;
map<int, bool> can;

void dfs(int x) {
    if (*lebnd.rbegin() <= val[x] && *ribnd.begin() >= val[x]) can[val[x]] = 1;
    ribnd.insert(val[x]);
    if (son[x][0] != -1) dfs(son[x][0]);
    ribnd.erase(ribnd.find(val[x]));
    lebnd.insert(val[x]);
    if (son[x][1] != -1) dfs(son[x][1]);
    lebnd.erase(lebnd.find(val[x]));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d %d", &val[i], &son[i][0], &son[i][1]);
        if (son[i][0] != -1) pa[son[i][0]] = i;
        if (son[i][1] != -1) pa[son[i][1]] = i;
    }
    rt = 1;
    while (pa[rt]) rt = pa[rt];
    lebnd.insert(-INF), ribnd.insert(INF);
    dfs(rt);
    for (int i = 1; i <= n; i ++) if (!can.count(val[i])) ans ++;
    printf("%d\n", ans);
    return 0;
}