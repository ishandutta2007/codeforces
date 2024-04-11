#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 105;

int T, N, K;
char s[3][MaxN];
bool dp[2][3];

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < 3; i++) scanf(" %s", s[i]);
        std::fill(dp[0], dp[0]+3, false);
        for (int i = 0; i < 3; i++) if (s[i][0] == 's') dp[0][i] = true;
        int c = 0, cur = 1, prev = 0;
        bool allg = false;
        while (c < N) {
            std::fill(dp[cur], dp[cur]+3, false);
            for (int r = 0; r < 3; r++) if (dp[prev][r]) {
                if (c+1 < N && s[r][c+1] != '.') continue;
                else {
                    for (int rr = r-1; rr <= r+1; rr++) {
                        if (rr < 0 || 3 <= rr) continue;
                        bool good = true;
                        for (int cc = c+1; cc <= c+3 && cc < N; cc++) {
                            if (s[rr][cc] != '.') good = false;
                        }
                        if (good) dp[cur][rr] = true;
                    }
                }
            }
            c += 3;
            std::swap(cur, prev);
        }
        for (int r = 0; r < 3; r++) if (dp[prev][r]) allg = true;
        printf("%s\n", (allg ? "YES" : "NO"));
    }
}