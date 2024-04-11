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
long long a[110000], S = 0;
long long s[110000];
long long d[110000][4];

long long t[110000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]), S += a[i], s[i] = s[i - 1] + a[i];

    if (S % 3LL != 0LL)
    {
        printf("0\n");
        return 0;
    }

    long long r = S / 3LL;

    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == r)
            d[i][1] = 1;
        t[i] = t[i - 1] + d[i][1];
    }

    for (long long i = 2; i <= 3; i ++)
    {
        for (int j = 1; j <= n; j ++)
            if (s[j] == i * r)
                d[j][i] = t[j - 1];
        for (int j = 1; j <= n; j ++)
            t[j] = t[j - 1] + d[j][i];
    }

    cout << d[n][3] << endl;

    return 0;
}