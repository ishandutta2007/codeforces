#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n, t;
int x[2000], a[2000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i ++)
        scanf("%d%d", &x[i], &a[i]);
    for (int i = 1; i <= n; i ++)
        x[i] *= 2;

    int res = 0;
    for (int i = -10000; i <= 10000; i ++)
    {
        bool good = false;
        for (int j = 1; j <= n; j ++)
            if (i - t == x[j] - a[j] || i - t == x[j] + a[j] || i + t == x[j] - a[j] || i + t == x[j] + a[j])
                good = true;
        if (!good) continue;

        good = true;
        for (int j = 1; j <= n; j ++)
        {
            if (x[j] - a[j] >= i + t) continue;
            if (x[j] + a[j] <= i - t) continue;
            good = false;
        }
        res += good;
    }
    printf("%d\n", res);
    return 0;
}