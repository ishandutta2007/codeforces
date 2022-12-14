#include<bits/stdc++.h>
using namespace std;

long long a, b, x, y, z, yy, bl, s = 0;

int main()
{
    scanf("%lld %lld %lld %lld %lld", &a, &b, &x, &y, &z);
    yy = 2 * x + y, bl = y + 3 * z;
    if (a < yy) s += yy - a;
    if (b < bl) s += bl - b;
    printf("%lld\n", s);

    return 0;
}