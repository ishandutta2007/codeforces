#include <iostream>
using namespace std;
typedef long long LL;
const int NICO = 1000000 + 10;
const int MOD  = 1000000000 + 7;
int n, m;
LL dp[NICO], pow_m[NICO];
int main()
{
    cin >> n >> m;
    pow_m[0] = dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        pow_m[i] = pow_m[i-1] * m % MOD;
    }
    for(int i=0;i<n;i++)
    {
        dp[i+1] = (dp[i] * (2*m-1) + pow_m[i]) % MOD; 
    }
    cout << dp[n] << endl;
}