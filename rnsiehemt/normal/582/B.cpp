#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
#define pb push_back
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); } 
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); } 
typedef long long ll;

const int MaxD = 25;

int N, T, a[305], dp[MaxD][305][305], ans[305], ansans;

int main()
{
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    
    int bound = 0;
    for (int i = 0; i < N; i++) {
        int min = 1e9;
        for (int j = 0; j < N; j++) if (a[j] >= bound) domin(min, a[j]);
        for (int j = 0; j < N; j++) if (a[j] == min) a[j] = bound;
        bound++;
    }
    //for (int i = 0; i < N; i++) printf("%d%c", a[i], " \n"[i == N-1]);

    for (int i = 0; i < N; i++) {
        for (int s = 0; s <= a[i]; s++) {
            int max = -1e9;
            for (int e = s; e <= a[i]; e++) {
                domax(max, dp[0][s][e]);
            }
            domax(dp[0][s][a[i]], max + 1);
        }
    }
    //for (int s = 0; s < N; s++) for (int e = s; e < N; e++) printf("%d %d %d\n", s, e, dp[0][s][e]);

    for (int d = 0; d+1 < MaxD; d++) {
        for (int s = 0; s < 100; s++) for (int m = s; m < 100; m++) for (int e = m; e < 100; e++) {
            domax(dp[d+1][s][e], dp[d][s][m] + dp[d][m][e]);
        }
    }

    for (int i = 0; i < MaxD; i++) if (T & (1 << i)) {
        for (int j = 99; j >= 0; j--) for (int k = 99; k >= j; k--)
            domax(ans[k], ans[j] + dp[i][j][k]);
    }

    for (int i = 0; i < 100; i++) domax(ansans, ans[i]);
    printf("%d\n", ansans);
}