#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, d[N], id[N];
int m, r[N];

bool cmp(int i, int j) {
    return d[i] > d[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &d[i]), id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1; i < n; i ++) printf("%d %d\n", 2 * id[i] - 1, 2 * id[i+1] - 1);
    m = n;
    for (int i = 1; i <= n; i ++) r[i] = 2 * id[i] - 1;
    for (int i = 1; i <= n; i ++) {
        int x = d[id[i]] + i - 1;
        assert(x <= m);
        printf("%d %d\n", 2 * id[i], r[x]);
        if (x == m) r[++m] = 2 * id[i];
    }
}