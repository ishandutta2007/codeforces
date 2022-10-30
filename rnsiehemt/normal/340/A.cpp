#include <cstdio>

int x, y, z, a, b;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    scanf("%d%d%d%d", &x, &y, &a, &b);
    z = (x/gcd(x, y)) * y;
    printf("%d\n", (b/z)-((a-1)/z));
}