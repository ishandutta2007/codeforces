#include<bits/stdc++.h>
using namespace std;
int Solve(int k, int m)
{
    long long c, r, used = 0, n = 1;
    for (int i = 1; i <= k; i++)
    {
        for (r = c = 1; r <= min(i, k - i) && c < 1e9; r ++)
            c = c * (k - r + 1) / r;
        c = min(c, (1ll * m * k - used) / i);
        used += c * i; n += c;
        if (!c || n >= 1e9)
            return (min(n, (long long)1e9));
    }
    return (n);
}
int main()
{
    int n, m, q, l, r, md;
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d%d", &n, &m);
        l = -1, r = n;
        while (r - l > 1)
        {
            md = (l + r) >> 1;
            if (Solve(md, m) >= n)
                r = md;
            else
                l = md;
        }
        printf("%d\n", r);
    }
    return (0);
}