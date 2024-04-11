#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

char c[2002][2002];
ll dp[2002][2002];
ll dpd[2002][2002];
int r[2002];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int j = 0; j < m; j++) c[0][j] = '.';
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
            if(c[i][j] == 'R') r[j]++;
        }
    }
    dp[0][0] = 1;
    dpd[r[0]][0] = 1;
    for(int i = 1; i <= n; i++){
        int k = m - 1;
        ll s = 0;
        for(int j = m - 1; j >= 0; j--){
            if(c[i][j] == 'R') r[j]--;
            for(; k >= 0; k--){
                s = (s + dp[i - 1][k] - dpd[n + 1 - i][k] + MOD) % MOD;
                if(c[i][k] == 'R'){
                    k--;
                    break;
                }
            }
            dp[i][j] = s;
            s = (s - dp[i - 1][j] + dpd[n + 1 - i][j] + MOD) % MOD;
            dpd[r[j]][j] = (dpd[r[j]][j] + s) % MOD;
        }
    }
    cout << dp[n][m - 1] << endl;
}