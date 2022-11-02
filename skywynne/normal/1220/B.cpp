// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, q, A[N][N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            scanf("%d", &A[i][j]);
    for (int i = 1; i <= n; i ++)
    {
        int j = i % n + 1;
        int k = j % n + 1;
        printf("%lld ", (long long)sqrt(1LL * A[i][k] * A[i][j] / A[j][k]));
    }
    return 0;
}