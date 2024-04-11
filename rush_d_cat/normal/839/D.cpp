#include <iostream>
#include <vector>
using namespace std;
const int NICO = 200000+10;
const int MAKI = 1000000+10;
typedef long long LL;
const LL MOD = 1000000007;

int n, a[NICO];

vector<int> v[MAKI];
LL dp[MAKI], f[MAKI];
LL ways[MAKI];
int prime[MAKI], np[MAKI];

void init() {

    f[0] = 1;
    for(LL i = 1; i <= 1000000; i ++) {
        f[i] = 2L * f[i-1] % MOD;
    }
    
    for(LL i = 1; i <= 1000000; i ++) {
        ways[i] = (LL) i * f[i-1];
        ways[i] %= MOD;
    }

    for(int i = 2; i <= 1000000; i ++) {
        if(np[i] == 1) continue;
        prime[++prime[0]] = i; 
        for(int j = i; j <= 1000000; j += i) {
            np[j] = 1;
        }
    }

}




int main() {

    init(); 

    scanf("%d", &n);

    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);

        for(int j = 1; j * j <= a[i]; j ++) {
            if(a[i] % j == 0) {
                v[j].push_back(i);
                if(j * j != a[i]) {
                    v[a[i] / j].push_back(i);
                }
            }
        }

    }

    LL result = 0;

    for(int i = 1000000; i >= 2; i --) 
    {

        if(v[i].size() == 0) continue;

        LL len = v[i].size();
        LL tmp = ways[len];

        
        for(int j = 2 * i; j <= 1000000; j += i) {
            tmp -= dp[j];
            tmp %= MOD;
        }

        dp[i] = tmp;
        //printf("dp[%d] = %d\n", i, dp[i]);
        result += tmp * (LL)i % MOD;
        result = (result % MOD + MOD) % MOD;

    }

    cout << result << endl;

}