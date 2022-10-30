#include <cstdio>
#include <algorithm>

long long x, y, m, c;

int main()
{
    scanf("%I64d%I64d%I64d", &x, &y, &m);
    if (x >= m || y >= m) printf("0\n");
    else if (x <= 0ll && y <= 0ll) printf("-1\n");
    else {
        if (x > y) std::swap(x, y);
        while (y < m) {
            c += (y-x)/y + 1;
            x += y*((y-x)/y + 1);
            std::swap(x, y);
        }
        printf("%I64d\n", c);
    }
}