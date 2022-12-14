//yunpok_B
#include<bits/stdc++.h>
using namespace std;
int SS[27][27];
char s[27][27];
int sum(int a, int b, int c, int d) {
    return SS[c][d] - (SS[c][b-1] + SS[a-1][d] - SS[a-1][b-1]);
}
int main(){
    int n, m;
   // freopen("B.in","r",stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%s", s[i]);
    SS[1][1] = (s[0][0] == '1');
    for(int i = 2; i <= n; i ++) SS[i][1] = SS[i-1][1] + (s[i-1][0] == '1');
    for(int i = 2; i <= m; i ++) SS[1][i] = SS[1][i-1] + (s[0][i-1] == '1');
    for(int i = 2; i <= n; i ++) {
        for(int j = 2; j <= m; j ++) {
            SS[i][j] = SS[i][j-1] + SS[i-1][j] - SS[i-1][j-1] + (s[i-1][j-1] == '1');
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            for(int ii = 1; ii <= n; ii ++) {
                for(int jj = 1; jj <= m; jj ++) {
                    if(i + ii > n) continue;
                    if(j + jj > m) continue;
                    if(sum(i + 1, j + 1 ,i + ii, j + jj) == 0) {
                        ans = max(ans, 2 * (ii + jj));
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}