#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll t[5005][5005];

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    ll a[5005];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < n; j++) t[k][j] = 1;
    for(int i = k - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(j > 0) t[i][j] = (t[i][j] + t[i + 1][j - 1]) % MOD;
            if(j < n - 1) t[i][j] = (t[i][j] + t[i + 1][j + 1]) % MOD;
        }
    }
    ll s[5005]{0};
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < n; j++) s[j] = (s[j] + t[i][j] * t[k - i][j]) % MOD;
    }
    ll ans = 0;
    for(int j = 0; j < n; j++) ans = (ans + s[j] * a[j]) % MOD;
    while(q--){
        int i;
        ll x;
        cin >> i >> x;
        i--;
        ans = (ans + s[i] * (x - a[i]) % MOD + MOD) % MOD;
        a[i] = x;
        cout << ans << endl;
    }
}