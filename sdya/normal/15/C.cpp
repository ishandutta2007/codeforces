#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n;
long long x[200000], a[200000];

long long calc(long long n, long long md, long long d)
{
    long long p = (n / md) * d;
    long long q = n % md;
    if (q >= d) p += q - d + 1;
    return p;
}

long long calc(long long l, long long r, long long md, long long d)
{
    return calc(r, md, d) - calc(l - 1LL, md, d);
}

long long p2[70], b[70];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld%lld", &x[i], &a[i]);
    long long res = 0;
    p2[0] = 1LL;
    for (long long i = 1; i <= 65; i ++)
        p2[i] = p2[i - 1] * 2LL;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= 60; j ++)
            b[j - 1] += calc(x[i], x[i] + a[i] - 1, p2[j], p2[j - 1]), b[j - 1] %= 2;

    for (long long i = 0; i < 60; i ++)
        res += p2[i] * b[i];
    if (res == 0LL) printf("bolik\n"); else printf("tolik\n");

    /*res = 0;
    for (int i = 1; i <= n; i ++)
        for (long long j = 0; j < a[i]; j ++)
            res ^= (x[i] + j);
    if (res == 0LL) printf("bolik\n"); else printf("tolik\n");*/
    return 0;
}