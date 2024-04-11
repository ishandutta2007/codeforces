// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 74;
int n, q, A[N], S[N];
inline int Get(int l, int r)
{
    l += n * 3;
    r += n * 3;
    int Mx = 0;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1) Mx = max(Mx, S[l ++]);
        if (r & 1) Mx = max(Mx, S[-- r]);
    }
    return (Mx);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &A[i]), A[i + n] = A[i + n + n] = A[i];
    for (int i = 0; i < n * 3; i ++)
        S[i + n * 3] = A[i];
    for (int i = n * 3 - 1; ~ i; i --)
        S[i] = max(S[i << 1], S[i << 1 ^ 1]);
    if (* max_element(A, A + n) <= * min_element(A, A + n) * 2)
    {
        for (int i = 0; i < n; i ++)
            printf("-1 ");
        printf("\n");
        return 0;
    }
    int r = 0;
    for (int i = 0; i < n; i ++)
    {
        r = max(r, i + 1);
        while (Get(i, r) <= 2 * A[r])
            r ++;
        printf("%d ", r - i);
    }
    return 0;
}