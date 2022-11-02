#include <bits/stdc++.h>
using namespace std;

#define N 11

int dp[N][N], cnt[N][N];
char s[2000200];

int main() {
    scanf("%s", s);
    int n = strlen(s); if (s[0] != '0') cnt[0][s[0]-'0'] ++;
    for (int i = 1; i < n; i ++) cnt[s[i-1]-'0'][s[i]-'0'] ++;
    for (int x = 0; x < 10; x ++, puts("")) {
        for (int y = 0; y < 10; y ++) {
            for (int st = 0; st < 10; st ++) {
                memset(dp[st], -1, sizeof dp[st]);
                queue <int> Q;
                dp[st][(st+x)%10] = 0; Q.push((st + x) % 10);
                dp[st][(st+y)%10] = 0; Q.push((st + y) % 10);
                while (!Q.empty()) {
                    int u = Q.front(); Q.pop();
                    int v = (u + x) % 10;
                    if (dp[st][v] < 0) {
                        dp[st][v] = dp[st][u] + 1;
                        Q.push(v);
                    }
                    v = (u + y) % 10;
                    if (dp[st][v] < 0) {
                        dp[st][v] = dp[st][u] + 1;
                        Q.push(v);
                    }
                }
            }
            int rlt = 0;
            for (int i = 0; i < 10; i ++) {
                for (int j = 0; j < 10; j ++) {
                    if (!cnt[i][j]) continue;
                    if (dp[i][j] < 0) rlt = -1;
                    else if (rlt >= 0) rlt += dp[i][j] * cnt[i][j];
                }
            }
            printf("%d ", rlt);
        }
    }

    return 0;
}