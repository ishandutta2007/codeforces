#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main()
{
    int n;
    cin >> n;
    ll a[502];
    for(int i = 0; i < n; i++){
        char p;
        cin >> p;
        if(p == '-') a[i] = -1;
        else cin >> a[i];
    }
    ll ans = 0;
    for(int u = 0; u < n; u++){
        if(a[u] == -1) continue;
        ll dp[502]{0};
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            ll d[502]{0};
            for(int j = 0; j <= n; j++){
                d[j] = (d[j] + dp[j]) % MOD;
                if(i == u) continue;
                else if(a[i] == -1){
                    if(i < u) d[max(0, j - 1)] = (d[max(0, j - 1)] + dp[j]) % MOD;
                    else if(j > 0) d[j - 1] = (d[j - 1] + dp[j]) % MOD;
                }
                else if(a[i] < a[u] || (i < u && a[i] == a[u])) d[j + 1] = (d[j + 1] + dp[j]) % MOD;
                else d[j] = (d[j] + dp[j]) % MOD;
            }
            swap(dp, d);
        }
        for(int j = 0; j <= n; j++) ans = (ans + dp[j] * a[u]) % MOD;
    }
    cout << ans << endl;
}