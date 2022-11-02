#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

long long n;
long long j;
long long x[200000], y[200000];
long long px[300000], py[300000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld%lld", &n, &j);
    scanf("%lld%lld", &px[0], &py[0]);
    for (int i = 0; i < n; i ++)
        scanf("%lld%lld", &x[i], &y[i]);

    for (int i = 0; i < 2 * n; i ++)
        px[i + 1] = 2LL * x[i % n] - px[i], py[i + 1] = 2LL * y[i % n] - py[i];

    long long md = j % (2 * n);
    printf("%lld %lld\n", px[md], py[md]);

    return 0;
}