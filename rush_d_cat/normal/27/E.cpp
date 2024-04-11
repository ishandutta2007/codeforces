#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;

int n; vector<int> v;
int p[102], notp[102];
LL dp[1002][20];

void init() {


    for(int i = 1; i <= 1000; i ++) {
        for(int j = 0; j < 20; j ++) {
            dp[i][j] = 2e18;
        }
    }

    dp[1][1] = 1; dp[1][0] = 1;

    for(int i = 2; i < 50; i ++) {
        dp[i][1] = dp[i-1][1] * 2L;
    }

    for(int i = 2; i <= 100; i ++) {
        
        if(notp[i] == 1) continue;
        
        p[++p[0]] = i; 
        for(int j = i; j <= 100; j += i) {
            notp[j] = 1;
        }
    }
}

int main() {
    cin >> n; init();

    for(int i = 2; i <= n; i ++) {
        for(int j = 1; j < i; j ++) if(i % j == 0) {
            for(int k = 1; k < 20; k ++) {
                LL tmp = dp[j][k-1]; bool ok = 1;
                
                for(int t = 1; t < i / j; t ++) {
                    if(tmp > 2e18 / p[k]) {
                        ok = 0;
                        break;
                    }
                    tmp = tmp * p[k];
                }

                if(ok) dp[i][k] = min(dp[i][k], tmp); 
            }
        }
    }


    for(int i = 1; i <= n; i ++) {
        for(int k = 1; k <= 19; k ++) {
            //printf("dp[%d][%d] = %lld\n", i, k, dp[i][k]);
        }
    }

    LL ans = 1e18;
    for(int i = 0; i < 20; i ++) {
        ans = min(ans, dp[n][i]);
    }
    printf("%lld\n", ans);

}