#include <bits/stdc++.h>
using namespace std;

int n, b, p;
int x, y;

void calc(int n) {
    if (n == 1) return;
    int k = 1;
    while (k <= n) k <<= 1; k /= 2;
    n -= k;
    x += k * b + k / 2;
    calc(n + k / 2);
}

int main() {
    scanf("%d %d %d", &n, &b, &p);
    calc(n);
    printf("%d %d\n", x, n * p);
    return 0;
}