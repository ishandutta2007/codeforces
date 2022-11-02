#include <bits/stdc++.h>
using namespace std;

int s, lim, n;
vector <int> ans, fi[20];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%d %d", &s, &lim);
    for (int i = 1; i <= lim; i ++) fi[__builtin_ctz(i)].push_back(i);
    for (int i = 19; i >= 0 && s; i --) {
        int sz = fi[i].size(), m = min(sz, s / (1 << i));
        n += m;
        s -= (1 << i) * m;
        for (int j = 0; j < m; j ++) ans.push_back(fi[i][j]);
    }
    if (!s) {
        printf("%d\n%d", n, ans[0]);
        for (int i = 1; i < n; i ++) printf(" %d", ans[i]);
        puts("");
    }
    else puts("-1");

    return 0;
}