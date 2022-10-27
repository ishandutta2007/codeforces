#include <iostream>
#include <cstring>
using namespace std;
int T, n, m;
char s[10][302];
int ok[10][302], dp[10][302];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= 3; i ++)
            scanf("%s", s[i]);

        memset(ok, 0, sizeof(ok));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 3; i ++)
            for (int j = 0; j < n; j ++)
                if (s[i][j] >= 'A' && s[i][j] <= 'Z') ok[i][j] = 1;

        for (int i = 1; i <= 3; i ++)
            if (s[i][0] == 's') dp[i][0] = 1;

        bool valid = 0;
        for (int i = 1; i <= 111; i ++) {
            if (i % 3) continue;

            for (int j = 1; j <= 3; j ++) {
                for (int d = -1; d <= 1; d ++) {
                    if (dp[j+d][i-3] && !ok[j+d][i-2] && !ok[j][i-2]
                        && !ok[j][i-1] && !ok[j][i])
                        dp[j][i] = 1;


                    if (i > 103 && dp[j][i])
                        valid = 1;
                }
            }
        }
        printf("%s\n", valid ? "YES" : "NO");

    }
}