#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

LL n, k;
LL cnt[4002], c[4002][4002];

void init() {
    for (int i = 0; i <= 4000; i ++) 
        c[i][0] = 1;

    for (int i = 1; i <= 4000; i ++)
        for (int j = 1; j <= i; j ++)
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
}

LL cac(int x) {
    LL res = 1;

    for (int t = 2; t*t <= x; t++) {
        int count = 0;
        while (x % t == 0)
            x /= t, count ++;

        res = res * c[count+k-1][k-1] % MOD;
    }

    if (x > 1) res = res * c[k][k-1] % MOD;
    return res;
}

int main() {
    init();
    cin >> n >> k;
    LL ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = (ans + cac(i)) % MOD;
    }   
    cout << ans << endl;    
}