#include <bits/stdc++.h>
using namespace std;
int n, x, p, q, a[100100];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &x);
        if (x > p) a[x] = 1, q = p, p = x;
        else if (x > q) a[p] --, q = x;
    }
    int ans = 1;
    for (int i = 1; i <= n; i ++) if (a[i] < a[ans]) ans = i;
    printf("%d\n", ans);
    return 0;
}