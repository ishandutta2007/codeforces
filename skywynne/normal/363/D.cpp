#include<bits/stdc++.h>
using namespace std;
int n, m, a, l, r, A[100010], P[100010];
int Func(int c)
{
    int k = a;
    for (int i = c - 1; i >= 0; i--)
    {
        k -= max(P[c - 1 - i] - A[i], 0);
        if (k < 0)
        {
            return (0);
        }
    }
    return (1);
}
int main()
{
    scanf("%d%d%d", &n, &m, &a);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &P[i]);
    }
    sort(A, A + n);
    sort(P, P + m);
    reverse(A, A + n);
    l = 0;
    r = min(n + 1, m + 1);
    while (r - l > 1)
    {
        if (Func((l + r) /2) == 0)
        {
            r = (l + r) / 2;
        }
        else
        {
            l = (l + r) / 2;
        }
    }
    long long k = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        k += P[l - 1 - i];
    }
    printf("%d %I64d", l, max(k - a, 1ll * 0));
    return (0);
}