#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    ll c[102], b[102];
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n - 1; i++) cin >> b[i];
    int q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        ll l[102];
        l[0] = x;
        for(int i = 1; i < n; i++) l[i] = l[i - 1] + b[i - 1];
        for(int i = 1; i < n; i++) l[i] += l[i - 1];
        ll dp[10002]{0};
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            ll d[10002]{0};
            for(int j = max(0ll, l[i]); j <= 10000; j++){
                for(int k = 0; k <= c[i] && j - k >= 0; k++) d[j] = (d[j] + dp[j - k]) % MOD;
            }
            swap(dp, d);
        }
        ll ans = 0;
        for(int i = max(0ll, l[n - 1]); i <= 10000; i++) ans = (ans + dp[i]) % MOD;
        cout << ans << endl;
    }
}