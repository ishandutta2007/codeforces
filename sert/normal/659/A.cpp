#include <bits/stdc++.h>
int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    printf("%d", (n * 200 + a + b - 1) % n + 1);
    return 0;
}