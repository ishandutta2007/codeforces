#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n & 1) res = res * r % MOD;
        r = r * r % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, greater<int>());
        ll f = 1;
        for(int i = 1; i <= n; i++) f = f * i % MOD;
        if(a[0] == a[1]){
            cout << f << endl;
            continue;
        }
        if(a[0] >= a[1] + 2){
            cout << 0 << endl;
            continue;
        }
        int r;
        for(r = 1; r < n; r++){
            if(a[r] != a[1]) break;
        }
        cout << f * (r - 1) % MOD * modpow(r, MOD - 2) % MOD << endl;
    }
}