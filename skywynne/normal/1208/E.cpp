// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 74;
int q, n, W, A[N], L[N], R[N];
long long P[N];
int main()
{
    scanf("%d%d", &q, &W);
    for (int i = 1; i <= q; i ++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &A[i]);
        for (int i = 1; i <= n; i ++)
        {
            L[i] = i - 1;
            while (L[i] && A[L[i]] <= A[i])
                L[i] = L[L[i]];
        }
        for (int i = n; i; i --)
        {
            R[i] = i + 1;
            while (R[i] <= n && A[R[i]] < A[i])
                R[i] = R[R[i]];
        }
        int len = W - n + 1;
        for (int i = 1; i <= n; i ++)
        {
            int l = i;
            if (L[i]) l = max(l, L[i] + len);
            int r = i + len - 1;
            if (R[i] <= n) r = min(r, R[i] - 1);
            if (A[i] < 0 && l <= r)
            {
                l = max(l, W - n + 1);
                r = min(r, n);
            }
            if (l <= r)
                P[l] += A[i], P[r + 1] -= A[i];
        }
    }
    for (int i = 1; i <= W; i ++)
    {
        P[i] += P[i - 1];
        printf("%lld ", P[i]);
    }
    return 0;
}