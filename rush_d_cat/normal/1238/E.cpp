#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
int n, m;
char s[N];
int dp[1<<20], c[22][22], tot[22];
int f[1<<20][20];
int lg[1<<20],cnt[1<<20];
int cac(int mask, int i) {
    int pos = cnt[mask] + 1;
    return (f[mask][i] - f[((1<<m)-1) ^ (mask) ^ (1<<i)][i]) * pos;
}
int main() {
    for(int i=0;i<20;i++) lg[1<<i] = i;
    for(int i=0;i<1<<20;i++) {
        for(int j=0;j<20;j++) if(i>>j&1) cnt[i] ++; 
    }
    scanf("%d%d%s", &n, &m, s+1);
    for(int i=0;i<1<<m;i++) dp[i] = 1e9;
    for(int i=1;i<n;i++) {
        c[s[i]-'a'][s[i+1]-'a'] ++;
        c[s[i+1]-'a'][s[i]-'a'] ++;
    }
    for(int j=0;j<m;j++)
    for(int i=1;i<1<<m;i++) {
        f[i][j] = f[i - (i&(-i))][j] + c[ lg[i&(-i)] ][j];
    }
    dp[0] = 0;
    for (int i = 0; i < 1<<m; i ++) {
        // printf("dp[%d] = %d\n", i, dp[i]);
        for (int j = 0; j < m; j ++) {
            if (!(i >> j & 1)) {
                dp[i | (1<<j)] = min(dp[i|(1<<j)], dp[i] + cac(i, j));
            }
        }
    }
    printf("%d\n", dp[(1<<m) - 1]);
}