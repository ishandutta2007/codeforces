// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 3003, Mod = 1e9 + 7;
int n, ts, A[N], M[N], C[N * N][2], dp[N][N];
inline void Add(int &a, int b)
{
    a += b;
    if (a >= Mod)
        a -= Mod;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]);
    for (int i = 4; i <= n; i ++)
    {
        M[i] |= (A[i] == 1 && A[i - 1] == 1 && A[i - 2] == 0 && A[i - 3] == 0);
        M[i] |= (A[i] == 1 && A[i - 1] == 0 && A[i - 2] == 1 && A[i - 3] == 0);
        M[i] |= (A[i] == 0 && A[i - 1] == 1 && A[i - 2] == 1 && A[i - 3] == 1);
        M[i] |= (A[i] == 1 && A[i - 1] == 1 && A[i - 2] == 1 && A[i - 3] == 1);
    }
    for (int l = 1; l <= n; l ++)
    {
        dp[l][l - 1] = 1;
        for (int r = l; r <= n; r ++)
        {
            if (r - l >= 0)
                Add(dp[l][r], dp[l][r - 1]);
            if (r - l >= 1)
                Add(dp[l][r], dp[l][r - 2]);
            if (r - l >= 2)
                Add(dp[l][r], dp[l][r - 3]);
            if (r - l >= 3 && !M[r])
                Add(dp[l][r], dp[l][r - 4]);
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; i ++)
    {
        int id = 0, j = i;
        while (C[id][A[j]])
            id = C[id][A[j]], j --;
        while (j)
            C[id][A[j]] = ++ ts, id = ts, Add(tot, dp[j][i]), j --;
        printf("%d\n", tot);
    }
    return 0;
}