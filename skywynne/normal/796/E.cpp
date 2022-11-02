#include<bits/stdc++.h>
#define Max(a, b) a = max((int)(a), (int)(b))
using namespace std;
const int N = 1059, K = 53;
int n, k, p, s, Mx, P[N][2], C[N];
int16_t dp[N][N][K * 2];
inline int F(int h) {return (max(h, -K) + K);}
inline Get(int l, int r, int w, int t)
{
    if (t < l)
        return (P[r][w] - P[l - 1][w]);
    return (P[r][w] - P[l - 1][w] - (C[t] - C[l - 1]));
}
int main()
{
    scanf("%d%d%d", &n, &p, &k);
    for (int w = 0, r; w <= 1; w ++)
    {
        scanf("%d", &r);
        for (int i = 1, a; i <= r; i++)
            scanf("%d", &a), P[a][w] ++, C[a] ++;
        for (int i = 1; i < N; i++)
            P[i][w] += P[i - 1][w];
    }
    for (int i = 1; i < N; i++)
        if (C[i]) s ++, C[i] --;
    for (int i = 1; i < N; i++)
        C[i] += C[i - 1];
    if (p >= 2 *  (n + k - 1) / k)
        return !printf("%d", s);
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= p; j ++)
            for (int h = - min(i, K); h < K; h ++)
            {
                if (i + h > n)
                    continue;
                if (j)
                    Max(dp[i][j][h + K], dp[i][j - 1][h + K]);
                Max(dp[i][j][h + K], dp[i][j][F(h - 1)]);
                Max(dp[i + 1][j][F(h - 1)], dp[i][j][h + K]);
                 if (h + k < K)
                    Max(dp[i][j + 1][F(h + k)], dp[i][j][h + K] + Get(i + h + 1, i + h + k, 1, i));
                Max(dp[i + k][j + 1][F(h - k)], dp[i][j][h + K] + Get(i + 1, i + k, 0, i + h));
            }
    for (int i = 0; i < N; i ++)
        for (int j = 0; j <= p; j ++)
            for (int h = 0; h < K + K; h ++)
                Max(Mx, dp[i][j][h]);
    return !printf("%d", Mx);
}