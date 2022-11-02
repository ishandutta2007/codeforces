#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = 0; a >>= 1;
    for (int i = 0; i <= c && (i << 1) <= n; i ++) {
        int d = n - (i << 1);
        ans += max(0, min(a, d) - max(d - b, 0) + 1);
    }
    printf("%d\n", ans);

    return 0;
}