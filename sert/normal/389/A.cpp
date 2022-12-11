#include <cstdio>
int gcd(int a, int b) {
    return (a * b ? gcd(b, a % b) : a + b);
}
int n, g, t;
int main() {
    scanf("%d%d", &n, &g);
    for (int i = 1; i < n; i++) {
        scanf("%d", &t);
        g = gcd(g, t);
    }
    printf("%d", g * n);
}