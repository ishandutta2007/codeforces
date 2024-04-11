#include <bits/stdc++.h>
using namespace std;

#define N 155
#define M 55

int n, nxt[N][3], cur[3];
char s[N];

int dp[N][M][M][M];
const int mod = 51123987;

inline void add(int &x, int y) {
    if ((x += y) >= mod) x -= mod;
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    int m = 0;
    for (int i = 0, c = 0; s[i]; i ++) {
        if (s[i] == c) continue;
        c = s[m++] = s[i];
    }
    cur[0] = cur[1] = cur[2] = m;
    for (int i = m - 1; i >= 0; i --) {
        cur[s[i]-'a'] = i;
        memcpy(nxt[i], cur, 12);
    }
    dp[0][0][0][0] = 1;
    int ans = 0;
    for (int i = 0; i < m; i ++) {
        for (int a = 0; a < M - 1 && a <= n; a ++) {
            for (int b = 0; b < M - 1 && a + b <= n; b ++) {
                for (int c = 0; c < M - 1 && a + b + c <= n; c ++) {
                    int d = dp[i][a][b][c];
                    if (!d) continue;
                    add(dp[nxt[i][0]][a+1][b][c], d);
                    add(dp[nxt[i][1]][a][b+1][c], d);
                    add(dp[nxt[i][2]][a][b][c+1], d);
                    if (a + b + c == n && abs(a - b) <= 1 && abs(b - c) <= 1 && abs(a - c) <= 1) add(ans, d);
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}