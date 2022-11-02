#include <bits/stdc++.h>
using namespace std;

#define N 1000005

int n, m, totc;
int deg[N], c[N];
vector<int> v[N];

int rt[N];
int find_rt(int h) {
    return rt[h] == h ? h : rt[h] = find_rt(rt[h]);
}

int join(int x, int y) {
    x = find_rt(x), y = find_rt(y);
    if (x != y) {
        rt[x] = y;
        return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) rt[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x == y) {
            totc ++;
            v[x].push_back(i);
        }
        else {
            deg[x] ++, deg[y] ++;
            v[x].push_back(i);
            v[y].push_back(i);
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (v[i].empty()) continue;
        int e = v[i][0];
        for (int j = 1; j < v[i].size(); j ++) join(e, v[i][j]);
    }
    bool flag = 0;
    for (int i = 2; i <= m && !flag; i ++) {
        if (join(1, i)) flag = 1;
    }
    if (flag) {
        printf("0\n");
        return 0;
    }
    long long ans = 0;
    ans += 1ll * totc * (totc - 1) / 2;
    ans += 1ll * totc * (m - totc);
    for (int i = 1; i <= n; i ++) ans += 1ll * deg[i] * (deg[i] - 1) / 2;
    printf("%I64d\n", ans);
}