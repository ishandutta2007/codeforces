// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int n, m, A[N][N];
int main()
{
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1)
        return !printf("0\n");
    if (n == 1)
    {
        for (int i = 1; i <= m; i ++)
            printf("%d ", i + 1);
        return 0;
    }
    if (m == 1)
    {
        for (int i = 1; i <= n; i ++)
            printf("%d\n", i + 1);
        return 0;
    }
    for (int i = 1; i <= n; i ++, printf("\n"))
        for (int j = 1; j <= m; j ++)
            printf("%d ", i * (j + n));
    return 0;
}