#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int t;
int n, m;
long long dx, dy;
int x1, y1, x2, y2;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++)
    {
        scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
        dx = x1 - x2, dy = y1 - y2;
        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;
        long long N = n, M = m;

        long long a = (N - dx) * (M - dy);
        long long c = 0LL;
        if (2LL * dx <= N && 2LL * dy <= M) c = (N - 2LL * dx) * (M - 2LL * dy);
        printf("%lld\n", N * M - (a + a - c));
    }
    return 0;
}