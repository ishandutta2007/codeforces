#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const LL INF = 1e9;
LL T, x, p, k;

vector<LL> pri; 
LL dp[1<<9];

void fac(LL p) 
{
    pri.clear();
    LL tmp = p;
    for (LL i = 2; i * i <= tmp; i ++) {
        if (tmp % i == 0) {
            pri.push_back(i);
            while(tmp % i == 0) tmp /= i;
        }
    }
    if (tmp > 1) pri.push_back(tmp);
    
    LL sz = pri.size();
    memset(dp, 0, sizeof(dp));

    for (LL s = 0; s < (1<<sz); s ++) {
        LL mul = 1, cnt = 0, big = 0;
        for (LL bit = 0; bit < sz; bit ++) {
            if ((s>>bit)&1) {
                cnt ++; 
                if (mul >= (INF + pri[bit] - 1) / pri[bit]) {
                    big = 1;
                    break;
                }
                mul = mul * (LL)pri[bit];
            }
        }
        if (big) {
            dp[s] = 0;
        } else {
            dp[s] = mul; 
            if (cnt % 2) dp[s] *= -1; 
        }
    }

}

LL cac(LL t) {
    LL ans = 0;
    for (LL i = 0; i < (1<<pri.size()); i ++) {
        if (dp[i] == 0) continue;
        ans += t / dp[i];
    }
    return ans;
}

int main() {
    scanf("%lld", &T);
    while (T --) {
        scanf("%lld %lld %lld", &x, &p, &k);
        fac(p); 
        LL sub = cac(x); 
        
        LL L = x, R = INF;

        while (R - L > 1) {
            LL mid = (L + R) >> 1;
            if (cac(mid) - sub < k)
                L = mid;
            else
                R = mid;
        }
        printf("%lld\n", L+1);
    }
}