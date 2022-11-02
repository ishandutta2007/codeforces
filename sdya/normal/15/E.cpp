#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

long long MD = 1000000009;
long long a[2000000], b[2000000], c[2000000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    scanf("%d", &n);
    n /= 2;
    a[1] = 2;
    a[2] = 6; b[2] = 0; c[2] = 1;
    for (int i = 3; i <= n; i ++)
    {
        b[i] = b[i - 1] * 2LL + 4LL, b[i] %= MD;
        c[i] = c[i - 1] * (b[i - 1] + 1), c[i] %= MD;
        a[i] = a[i - 1] + c[i] * (4LL + 4LL * b[i]), a[i] %= MD;
        
    }
    long long res = a[n] * a[n] + 1LL;
    res %= MD; res *= 2LL; res %= MD;
    printf("%lld\n", res);
    return 0;
}