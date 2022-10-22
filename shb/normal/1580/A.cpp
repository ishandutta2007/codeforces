#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
char s[410][410];
int sum[410][410];
int need[410], md[410];
int S[410], mi[410];

int rg(int X1, int X2, int Y1, int Y2) {
    return sum[X2][Y2] - sum[X1 - 1][Y2] - sum[X2][Y1 - 1] + sum[X1 - 1][Y1 - 1];
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++) {
            scanf("%s",s[i] + 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] -= '0';
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + s[i][j];
            }
        }
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 4; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    need[k] = j - i - 1 - rg(i + 1, j - 1, k, k);
                    md[k] = rg(i + 1, j - 1, k, k) + (s[i][k] == 0) + (s[j][k] == 0);
                }
                mi[0] = 1e9;
                S[0] = 0;
                for (int k = 1; k <= m; k++) {
                    S[k] = S[k - 1] + md[k];
                    mi[k] = min(mi[k - 1], need[k] - S[k]);
                    if (k >= 4) {
                        ans = min(ans, need[k] + S[k - 1] + mi[k - 3]);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}