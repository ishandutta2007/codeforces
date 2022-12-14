#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, v[N], le[N], ri[N];
bool g[N];

map<int, bool> mp;

void dfs(int nod, int L, int R){
    if (nod == -1 || L > R) return;
    int res = 0;
    if (v[nod] >= L && v[nod] <= R) mp[v[nod]] = 1;
    dfs(le[nod], L, min(R, v[nod] - 1));
    dfs(ri[nod], max(v[nod] + 1, L), R);
}

int main(){
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i ++) {
		scanf("%d %d %d", &v[i], &le[i], &ri[i]);
        if (le[i] != -1) g[le[i]] = 1;
        if (ri[i] != -1) g[ri[i]] = 1;
    }
    for (i = 1; i <= n; i ++) if (!g[i]) dfs(i, 0, (1 << 30));
    int res = 0;
    for (i = 1; i <= n; i ++) if (mp[v[i]] == 0) res ++;
    printf("%d\n", res);
    return 0;
}