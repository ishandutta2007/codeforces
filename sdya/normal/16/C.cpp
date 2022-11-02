#include <iostream>

using namespace std;

int a, b, x, y;
int ax, bx;

int gcd(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (a > b) return gcd(a % b, b);
    return gcd(b % a, a);
}

int main()
{
    scanf("%d%d%d%d", &a, &b, &x, &y);
    int A = a, B = b;
    int d = gcd(x, y);
    x /= d, y /= d;
    A -= A % x, B -= B % y;
    int t = min(A / x, B / y);
    A = x * t, B = y * t;

    printf("%d %d\n", A, B);

    return 0;
}