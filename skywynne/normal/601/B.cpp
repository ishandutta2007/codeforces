// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, q, m, A[N], D[N], L[N], R[N];
inline long long Get(int ql, int qr)
{
    m = qr - ql;
    for (int i = 1; i <= m; i ++)
        D[i] = abs(A[ql + i] - A[ql + i - 1]);
    for (int i = 1; i <= m; i ++)
    {
        L[i] = i - 1;
        while (L[i] && D[i] > D[L[i]])
            L[i] = L[L[i]];
    }
    for (int i = m; i; i --)
    {
        R[i] = i + 1;
        while (R[i] <= m && D[i] >= D[R[i]])
            R[i] = R[R[i]];
    }
    long long res = 0;
    for (int i = 1; i <= m; i ++)
        res += 1LL * (i - L[i]) * (R[i] - i) * D[i];
    return (res);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]);
    for (; q; q --)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n",  Get(l, r));
    }
    return 0;
}