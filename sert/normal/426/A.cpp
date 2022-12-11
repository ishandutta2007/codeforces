#include <cstdio>
int n, sum, mx, t, s;
int main() {
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (mx < t) mx = t;
        sum += t;
    }
    if (sum - mx > s) printf("NO\n");
    else printf("YES\n");
}