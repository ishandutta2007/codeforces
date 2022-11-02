#include <bits/stdc++.h>

/**
(a, b)  = (2kx + ex, ex)
    2kx = a - b
    ex  = b
    e <= 1
    ex <= x
    b <= x
    a - b = 2kx >= 2kb
    a - b >= 2kb
    2k <= (a - b) / b

    k = int((a - b) / (2b))
    x = (a - b) / 2k
    
(a, b) = ((2k + 1)x + ex, x - ex)
    (2k + 2)x = a + b
    x >= b
    a + b >= (2k + 2)b
    
    k = (a + b) / (2b) - 1
    x = (a + b) / (2k + 2)
*/
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b > a) {
        puts("-1");
        return 0;
    }
    if (a == b) {
        printf("%d\n", a);
        return 0;
    }
    assert(b < a);
    int k1 = (a - b) / b / 2;
    double x1;
    if (k1 > 0) {
        x1 = (a - b) / (2. * k1);
    } else {
        x1 = 1e18;
    }
//  for (int i = 1; i < 1000; ++i) for (int j = 1; j < i; ++j) assert((i + j) / j / 2 - 1 >= 0);
    int k2 = (a + b) / b / 2 - 1;
    assert(k2 >= 0);
    double x2;
    x2 = (a + b) / (2. * k2 + 2);
    printf("%.17f\n", std::min(x1, x2));
//  fprintf(stderr, "%f %f\n", x1, x2);
}