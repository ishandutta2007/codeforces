#include<bits/stdc++.h>
#define uint uint64_t
using namespace std;
const int N = 1e5 + 10, K = 12;
int n, k;
uint F[N][K];
inline void Add(int i, int tp, uint val)
{
    for (; i < N; i += i & -i)
        F[i][tp] += val;
}
inline uint Get(int i, int tp)
{
    uint ret = 0;
    for (; i; i -= i & -i)
        ret += F[i][tp];
    return (ret);
}
int main()
{
    scanf("%d%d", &n, &k); k ++;
    for (int i = 1, a; i <= n; i++)
    {
        scanf("%d", &a); Add(a, 1, 1);
        for (int j = 2; j <= k; j++)
            Add(a, j, Get(a - 1, j - 1));
    }
    return !printf("%llu", Get(n, k));
}