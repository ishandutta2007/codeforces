#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int n, ans;

int gcd(int a, int b) {
    if (a == 1 || b == 1) { return a + b - 2; }
    if (a == 0 || b == 0) { return n; }
    return gcd(b, a % b) + a / b;
}

int main() {
    scanf("%d", &n); ans = n;
    for (int i = 1; i <= n; i++) { ans = std::min(ans, gcd(n, i)); }
    printf("%d\n", ans);
    return 0;
}