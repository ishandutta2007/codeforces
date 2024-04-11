#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int c[1000005];
ll dp[1000005];
ll s[1000005];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i) c[j]++;
    }
    for(int i = 1; i <= n; i++){
        dp[i] = c[i];
        dp[i] = (dp[i] + s[i - 1]) % MOD;
        s[i] = (s[i - 1] + dp[i]) % MOD;
    }
    cout << dp[n] << endl;
}