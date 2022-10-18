#include <stdio.h>
#include <algorithm>
#include <iostream>
#define LL long long

LL n, p, tot, tot1, tot2;
LL s[100010], a[100010], b[100010];

struct Diff
{
    LL s, d, i;
} dif[100010];

bool cmp(const Diff a, const Diff b)
{
    return a.d < b.d;
}

int main()
{
    std::cin >> n >> p;
    for (int i=0; i<n; i++)
    {
        std::cin >> s[i] >> a[i] >> b[i];
        tot += s[i];
        if (a[i] > b[i]) tot1 += s[i];
        else tot2 += s[i];

        dif[i].s = s[i];
        dif[i].d = b[i] - a[i];
        dif[i].i = i;
    }
    LL piz = (tot + p - 1) / p;
    LL piz1 = (tot1 + p - 1) / p;
    std::sort(dif, dif+n, cmp);

    LL left = tot - (piz - piz1) * p;
    if (left < tot1) left = tot1;
    LL hap = 0;

    for (int i=0; i<n; i++)
    {
        if (left == 0)
        {
            hap += b[dif[i].i] * dif[i].s;
        }
        else
        {
            if (left >= dif[i].s)
            {
                hap += a[dif[i].i] * dif[i].s;
                left -= dif[i].s;
            }
            else
            {
                hap += a[dif[i].i] * left + b[dif[i].i] * (dif[i].s - left);
                left = 0;
            }
        }
    }
    LL piz2 = (tot2 + p - 1) / p;
    
    left = tot - (piz - piz2) * p;
    if (left < tot2) left = tot2;

    LL hap2 = 0;

    for (int i=n-1; i>=0; i--)
    {
        if (left == 0)
        {
            hap2 += a[dif[i].i] * dif[i].s;
        }
        else
        {
            if (left >= dif[i].s)
            {
                hap2 += b[dif[i].i] * dif[i].s;
                left -= dif[i].s;
            }
            else
            {
                hap2 += b[dif[i].i] * left + a[dif[i].i] * (dif[i].s - left);
                left = 0;
            }
        }
    }
    std::cout << std::max(hap, hap2) << '\n';
    return 0;
}