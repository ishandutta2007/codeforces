#include <iostream>
#include <map>
using namespace std;
typedef long long LL;

const LL MOD = 1000000000 + 7;
int r, g, h;
LL dp[2][200002];

int main() {
    cin >> r >> g; 
    h = 1000; while(h * (h + 1) / 2 > (r + g)) h --;
    
    int tot = h * (h + 1) / 2;
    int det = r + g - tot;

    if(r) dp[1][1] = 1;
    if(g) dp[1][0] = 1;

    for(int i=2;i<=h;i++) {
        for(int j=0;j<=r;j++) {
            dp[i%2][j] = dp[(i-1)%2][j];
            if(j>=i)dp[i%2][j] += dp[(i-1)%2][j-i];
            dp[i%2][j] %= MOD;
        }
    }

    LL res = 0; 
    for(int R = r; R >= max(r - det, 0); R --) {
        res += dp[h%2][R]; res %= MOD;
    }


    cout << res << endl;


}