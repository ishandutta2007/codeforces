#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    ll p[62];
    p[0] = 1;
    for(int i = 1; i <= 60; i++) p[i] = p[i - 1] * 2 % MOD;
    while(t--){
        int n;
        cin >> n;
        ll x[500005];
        int b[61]{0};
        for(int i = 0; i < n; i++){
            cin >> x[i];
            for(int j = 0; j < 60; j++){
                b[j] += ((x[i] >> j) & 1);
            }
        }
        ll s = 0;
        for(int i = 0; i < n; i++) s = (s + x[i]) % MOD;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll t = s, u = s;
            for(int j = 0; j < 60; j++){
                if((x[i] >> j) & 1){
                    u = (u + (n - b[j]) * p[j]) % MOD;
                }
                else{
                    t = (t + MOD - b[j] * p[j] % MOD) % MOD;
                }
            }
            ans = (ans + t * u) % MOD;
        }
        cout << ans << "\n";
    }
}