#include <cstdio>

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int a, b, n, m;

int main()
{
    scanf("%d%d%d", &a, &b, &n);
    while (true) {
        n -= gcd(n, a);
        if (!n) break;
        m = 1-m;
        n -= gcd(n, b);
        if (!n) break;
        m = 1-m;
    }
    printf("%d\n", m);
}