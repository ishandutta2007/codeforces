// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, LG = 19;
int n, id, A[N], B[N], Log[N];
pair < int , int > RMQ[LG][N];
int GetMin(int l, int r)
{
    int lg = Log[r - l];
    return min(RMQ[lg][l], RMQ[lg][r - (1 << lg)]).second;
}
int Solve(int l, int r)
{
    if (r - l <= 0)
        return 0;
    if (r - l == 1)
        return 1;
    int i = GetMin(l, r);
    return (max(Solve(l, i), Solve(i + 1, r)) + 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &B[i]);
        if (B[i] == 1)
            id = i;
        B[i + n] = B[i];
    }
    for (int i = 0; i < n; i ++)
        A[i] = B[i + id], RMQ[0][i] = make_pair(A[i], i);
    for (int j = 1; j < LG; j ++)
        for (int i = 0; i + (1 << j) <= n; i ++)
            RMQ[j][i] = min(RMQ[j - 1][i], RMQ[j - 1][i + (1 << (j - 1))]);
    for (int i = 2; i < N; i ++)
        Log[i] = Log[i >> 1] + 1;
    int le = 1, ri = n + 1, md;
    while (ri - le > 1)
    {
        md = (le + ri) >> 1;
        if (Solve(1, md) >= Solve(md, n))
            ri = md;
        else
            le = md;
    }
    if (max(Solve(1, le), Solve(le, n)) > max(Solve(1, le + 1), Solve(le + 1, n)))
        le ++;
    printf("%d %d\n", max(Solve(1, le), Solve(le, n)) + 1, (id + le) % n);
    return 0;
}