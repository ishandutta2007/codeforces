// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1, a2, k1, k2, n, m;
    scanf("%d%d%d%d%d", &a1, &a2, &k1, &k2, &n);
    if (k1 > k2) swap(k1, k2), swap(a1, a2);
    int Mn = 0, Mx = 0;
    m = a1 * (k1 - 1) + a2 * (k2 - 1);
    Mn = max(n - m, 0);
    Mx += min(n / k1, a1);
    n -= min(n / k1, a1) * k1;
    Mx += min(n / k2, a2);
    return !printf("%d %d\n", Mn, Mx);
}