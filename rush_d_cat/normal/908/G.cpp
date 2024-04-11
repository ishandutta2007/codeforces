#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 702;

char s[N]; int len;
const LL MOD = 1000000007;
LL dp[702][12][702][2];

LL dfs(int pos, int dig, int rem, int is_limit) {
    if (pos == len) 
        return rem == 0;

    if (dp[pos][dig][rem][is_limit] != -1)
        return dp[pos][dig][rem][is_limit];

    int lim = is_limit ? (s[pos+1]-'0') : 9;

    LL sum = 0;
    for (int i = 0; i <= lim; i ++) {
        sum += dfs(pos + 1, dig, ((i >= dig) ? max(rem-1,0) : rem), is_limit && i == lim);
        sum %= MOD;
    }
    //printf("%d %d %d %d %d %d\n", pos,dig,rem,is_limit,lim,sum);
    return dp[pos][dig][rem][is_limit] = sum;
}

int main() {   
    scanf("%s", s+1);
    len = strlen(s+1);

    LL ans = 0, cur = 1;
    memset(dp, -1, sizeof(dp));
    //cout << dfs(0, 8, 1, 1) << endl;
    //return 0;
    
    for (int i = 1; i <= len; i ++) {
        for (int j = 1; j <= 9; j ++) {
            LL tmp = dfs(0, j, i, 1);
            //printf("%d %d %lld\n", j, i, tmp);
            ans = (ans + cur * tmp % MOD) % MOD; 
        }
        cur = cur * 10L % MOD;
    }
    printf("%lld\n", ans);
    
}