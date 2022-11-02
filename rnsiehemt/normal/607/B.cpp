#include <bits/stdc++.h>
template<typename T> void domin(T &a, T b) { if (b < a) a = b; }

const int MaxN = 505;

int N, c[MaxN], dp[MaxN][MaxN];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", c+i);
        dp[i][i] = 0;
    }
    for (int l = 1; l <= N; l++) {
        for (int a = 0; a+l <= N; a++) {
            int b = a+l;
            dp[a][b] = dp[a+1][b] + 1;
            if (a+1 < b && c[a] == c[a+1]) domin(dp[a][b], dp[a+2][b] + 1);
            for (int i = a+2; i < b; i++) if (c[a] == c[i]) domin(dp[a][b], dp[a+1][i] + dp[i+1][b]);
        }
    }
    printf("%d\n", dp[0][N]);
}