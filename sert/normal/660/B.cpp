#include <bits/stdc++.h>
int n, m;
void pr(int x) {
    if (x <= m)
        printf("%d ", x);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        pr(n * 2 + i * 2 + 1);
        pr(i * 2 + 1);
        pr(n * 2 + i * 2 + 2);
        pr(i * 2 + 2);
    }
    return 0;
}