#include <bits/stdc++.h>
using namespace std;

int n;

bool range(int x) {
    if(x < 1 || x > n) return 0;
    return 1;
}
int main() {
    ///freopen("b.in", "r", stdin);
    int a, b, c, d;
    scanf("%d %d %d %d %d", &n, &a, &b, &d, &c);
    int tot = 0;
    for(int x  = 1; x <= n; x ++) {
        if(range(x + b - d ) && range(x + a - c) && range(x + a + b - c - d)) tot ++;
    }
    printf("%I64d\n", 1ll * n * tot);
}