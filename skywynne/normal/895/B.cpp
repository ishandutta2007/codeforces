#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 10;
long long n, x, k, A[MXN], t;
long long c, l, r;
long long getlow(long long a)
{
    long long y = ((a + x - 1) / x) * x;
    if (k == 0)
        return (a);
    y += (k - 1) * x;
    return (y);
}
long long gethigh(long long a)
{
    long long y = ((a + x - 1) / x) * x;
    y += (k) * x;
    return (y);
}
int main()
{
    scanf("%I64d%I64d%I64d", &n, &x, &k);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &A[i]);
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++)
    {
        l = getlow(A[i]);
        r = gethigh(A[i]);
        int lx = lower_bound(A + 1, A + n + 1, l)- A - 1;
        int rx = lower_bound(A + 1, A + n + 1, r)- A - 1;
        c += (rx - lx);
    }
    printf("%I64d", c);
	return (0);
}