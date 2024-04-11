// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 21;
int q, n, A[N], R[N][2];
inline void Relax(int i, int a, int b)
{
    int c = R[i][0], d = R[i][1];
    if (a < b) swap(a, b);
    R[i][0] = max(a, c);
    R[i][1] = 0;
    if (b != R[i][0]) R[i][1] = max(R[i][1], b);
    if (d != R[i][0]) R[i][1] = max(R[i][1], d);
    if (min(a, c) != R[i][0]) R[i][1] = max(R[i][1], min(a, c));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]);
    for (int i = n; i; i --)
        Relax(A[i], i, 0);
    for (int i = N - 1; i; i --)
        for (int j = 0; j < 21; j ++)
            if ((i >> j) & 1)
                Relax(i ^ (1 << j), R[i][0], R[i][1]);
    int Max = 0;
    for (int i = 1; i <= n - 2; i ++)
    {
        int Mx = 0;
        for (int j = 20; ~ j; j --)
            if (!((A[i] >> j) & 1))
                if (R[(Mx | (1 << j))][1] > i)
                    Mx |= (1 << j);
        if (R[Mx][1] > i)
            Max = max(Max, Mx | A[i]);
    }
    printf("%d\n", Max);
    return 0;
}