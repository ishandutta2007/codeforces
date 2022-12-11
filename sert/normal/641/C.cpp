#include <bits/stdc++.h>

using namespace std;

int a[500500], b[500500];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, q;
    int p1 = 1;
    int p2 = 1;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2) a[i / 2 + 1] = i; else b[i / 2] = i;
    }
    int tt = 0;
    for (int i = 0; i < q; i++)
    {
        int tp;
        scanf("%d", &tp);
        if (tp == 2)
        {
            tt = 1 - tt;
            swap(p1, p2);
        }
        if (tp == 1)
        {
            int x;
            scanf("%d", &x);
            if (x % 2 == 0)
            {
                p1 = (p1 - (x / 2) + (n / 2) - 1) % (n / 2) + 1;
                p2 = (p2 - (x / 2) + (n / 2) - 1) % (n / 2) + 1;
            }
                else
            {
                x--;
                p1 = (p1 - (x / 2) + (n / 2) - 1) % (n / 2) + 1;
                p2 = (p2 - (x / 2) + (n / 2) - 1) % (n / 2) + 1;
                tt = 1 - tt;
                swap(p1, p2);
                p1 = (p1 - 1 + (n / 2) - 1) % (n / 2) + 1;
            }
        }
    }
    if (tt) swap(a, b);
    for (int i = 0; i < n / 2; i++)
    {
        printf ("%d %d ", a[p1], b[p2]);
        p1++;
        p2++;
        if (p1 > n / 2) p1 = 1;
        if (p2 > n / 2) p2 = 1;
    }
    return 0;
}