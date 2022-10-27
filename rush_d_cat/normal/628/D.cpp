#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
const int N = 2002;
int m, d, n;
int dp[2002][2002][2];
char s[N];

LL dfs(int pos, int mod, int is_lim) {
    if (pos == n)
        return mod == 0;

    if (dp[pos][mod][is_lim] != -1)
        return dp[pos][mod][is_lim];

    int lim = is_lim ? s[pos+1]-'0' : 9;
    
    LL sum = 0;     
    for (int i = 0; i <= lim; i ++) {
        if ((pos+1)%2 == 0 && i == d) {
            sum += dfs(pos+1, (mod*10+i) % m, is_lim && i == lim);
            sum %= MOD;
        } 
        if ((pos+1)%2 == 1 && i != d) {
            sum += dfs(pos+1, (mod*10+i) % m, is_lim && i == lim);
            sum %= MOD;
        }
    }
    return dp[pos][mod][is_lim] = sum;
}

LL cac() {
    memset(dp, -1, sizeof(dp));
    n = strlen(s+1); 
    return dfs(0,0,1);
}

bool chk() {
    int result = 1;
    n = strlen(s + 1);

    int tmp = 0;
    for (int i = 1; i <= n; i ++) {
        if (i % 2 && s[i]-'0' == d) result = 0;
        if (i % 2 == 0 && s[i]-'0' != d) result = 0;
        tmp = (tmp * 10 + s[i]-'0') % m;
    }
    if (tmp != 0) result = 0;

    return result;
}



int main() {
    scanf("%d %d", &m, &d);
    scanf("%s", s+1);
    
    LL ans1 = cac();
    if (chk()) ans1 --;

    scanf("%s", s+1);
    LL ans2 = cac();

    printf("%lld\n", (ans2 - ans1 + MOD) % MOD);

}