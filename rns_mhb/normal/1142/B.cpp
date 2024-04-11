#include<bits/stdc++.h>
using namespace std;

#define N 200010

int p[N], _p[N], a[N], last[N], nxt[N][20], l[N], r[N];
bool ans[N];
vector <int> v[N], V[N];

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i ++) scanf("%d", &p[i]), _p[p[i]] = i;
    for(int i = 1; i <= m; i ++) scanf("%d", &a[i]), a[i] = _p[a[i]];
    for(int i = 1; i <= q; i ++) {
        scanf("%d%d", &l[i], &r[i]);
        v[l[i]].push_back(i);
    }
    for(int i = 1; i <= n; i ++) last[i] = m + 1;
    nxt[m+1][0] = m + 1;
    for(int i = m; i; i --) {
        nxt[i][0] = last[a[i] % n + 1];
        last[a[i]] = i;
    }
    for(int i = 1; i < 20; i ++) for(int j = 1; j <= m+1; j ++) nxt[j][i] = nxt[nxt[j][i-1]][i-1];
    for(int i = 1; i <= m; i ++) {
        int x = i;
        for(int j = 19; j >= 0; j --) if((n-1) >> j & 1) x = nxt[x][j];
        if(x != m + 1) V[i].push_back(x);
    }
    int mn = m + 1;
    for(int i = m; i; i --) {
        for(int j = 0; j < V[i].size(); j ++) mn = min(mn, V[i][j]);
        for(int j = 0; j < v[i].size(); j ++) ans[v[i][j]] = (mn <= r[v[i][j]]);
    }
    for(int i = 1; i <= q; i ++) putchar('0' + ans[i]);
}