#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
long long h, q, t, l = 1, r = 1, p, c;
pair < long long , long long > Pr;
priority_queue < pair < long long , long long > > P;
int main()
{
    scanf("%I64d %I64d", &h, &q);
    for (int i = 1; i < h; i++)
    {
        l *= 2;
    }
    r = 2 * l - 1;
    for (int i = 1; i <= q; i++)
    {
        scanf("%I64d %I64d %I64d %I64d", &t, &Pr.f, &Pr.s, &p);
        for (int j = 1; j <= h - t; j++)
        {
            Pr.f *= 2;
            Pr.s = Pr.s * 2 + 1;
        }
        if (p == 0)
        {
            Pr.f *= -1;
            Pr.s *= -1;
            P.push(Pr);
            continue;
        }
        if (l > Pr.s || r < Pr.f)
        {
            printf("Game cheated!");
            return (0);
        }
        l = max(l, Pr.f);
        r = min(r, Pr.s);
    }
    while (P.size() > 0)
    {
        Pr = P.top();
        P.pop();
        Pr.f *= -1;
        Pr.s *= -1;
        if (Pr.s < l || Pr.f > r)
        {
            continue;
        }
        if (Pr.f <= l)
        {
            l = Pr.s + 1;
            continue;
        }
        if (Pr.f > l)
        {
            if (c != 0 || Pr.f - l > 1)
            {
                printf("Data not sufficient!");
                return (0);
            }
            c = l;
            l = Pr.s + 1;
        }
    }
    if (c == 0 && r == l)
    {
        printf("%I64d", r);
        return (0);
    }
    if (c != 0 && l > r)
    {
        printf("%I64d", c);
        return (0);
    }
    if ((l <= r && c != 0) || (c == 0 && l < r))
    {
        printf("Data not sufficient!");
        return (0);
    }
    printf("Game cheated!");
    return (0);
}