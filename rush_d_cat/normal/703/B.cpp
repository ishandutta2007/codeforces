#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
typedef __int64 ll;
ll a[100000 + 10];
ll b[100000 + 10];
int main()
{
    ll n, k, i, t, sum1 = 0, sum2 = 0, res = 0, res1 = 0;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum1 += a[i];
    }
    for(i = 1; i <= k; i++)
    {
        cin >> t;
        b[t] = 1;
        sum2 += a[t];
    }
    for(i = 1; i <= n; i++)
    {
        if(b[i])
        {
            res += a[i] * (sum1 - a[i]);
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(b[i])
        {
            res1 += a[i] * (sum2 - a[i]);
        }
    }
    res -= (res1 / 2);

    a[n + 1] = a[1];
    b[n + 1] = b[1];
    for(i = 1; i <= n; i++)
    {
        if(b[i] || b[i + 1])
            continue;
        res += a[i] * a[i + 1];
    }
    cout << res << endl;
    return 0;
}