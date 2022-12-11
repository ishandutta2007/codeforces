#include <cstdio>

long long l, m, r, c1, c2, x, y, n1, n2, n;

int main() {
    scanf("%I64d%I64d%I64d%I64d", &c1, &c2, &x, &y);
    l = 0;
    r = 1e10;
    while (r - l > 1) {
        m = (l + r) / 2;
        n1 = m / x;
        n2 = m / y;
        n = m / (x * y);
        if (m - n >= c1 + c2 && m - n1 >= c1 && m - n2 >= c2)
            r = m;
        else
            l = m;
    }
    printf("%I64d\n", r);
}