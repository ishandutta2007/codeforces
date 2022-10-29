#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 111;
const int MOD = 1e9 + 7;;

map<long long, int> dp;
int power[N];

int go(int groups, int bound, int pos) {
    if (pos == -1)
        return 1;
    long long code = (bound * 40LL + groups) * 40LL + pos;
    if (dp.count(code))
        return dp[code];
    int &res = dp[code];

    if (bound >> pos & 1) {
        res += 1LL * power[groups] * go(groups, (1 << pos) - 1, pos - 1) % MOD;
        res %= MOD;
        if (groups) {
            res += 1LL * power[groups] * go(groups, bound ^ (1 << pos), pos - 1) % MOD;
            res %= MOD;
        }
        res += go(groups + 1, bound ^ (1 << pos), pos - 1);
        res %= MOD;
    } else {
        res = 1LL * power[groups] * go(groups, bound, pos - 1) % MOD;
    }
    
    return res;
}

int main() {
    int k;
    scanf("%d", &k);
    power[0] = power[1] = 1;
    for(int i = 2; i < N; i++) {
        power[i] = power[i - 1] * 2 % MOD;
    }
    printf("%d\n", go(0, k, 30));

    return 0;
}