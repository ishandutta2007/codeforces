#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, deg[N];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        deg[u] ++, deg[v] ++;
    }
    for (int i = 1; i <= n; i ++) if (deg[i] == 2) return puts("no"), 0;
    puts("yes");
    return 0;
}