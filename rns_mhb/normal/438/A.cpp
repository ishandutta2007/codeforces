#include <bits/stdc++.h>
using namespace std;
#define N 1111

int n, m, v[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    int rlt = 0;
    for (int i = 1; i <= n; i ++) scanf("%d", &v[i]);
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        rlt += min(v[x], v[y]);
    }
    printf("%d\n", rlt);

    return 0;
}