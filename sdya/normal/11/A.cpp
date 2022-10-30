#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

long long n, d;
long long a[10000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]);

    long long res = 0;
    for (int i = 2; i <= n; i ++)
        if (a[i] <= a[i - 1])
        {
            res += (a[i - 1] - a[i]) / d + 1LL;
            a[i] += ((a[i - 1] - a[i]) / d + 1LL) * d;
        }
    cout << res << endl;

    return 0;
}