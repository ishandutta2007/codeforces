#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get_rem(ll x, ll mod){
    ll rem  = x % mod;
    if(rem < 0) rem += mod;
    return rem;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<ll> x(n);
        for(int i = 0; i < n; ++i)
            cin >> x[i];

        sort(x.begin(), x.end());
        for(int i = 0; i < n - 1; ++i)
            x[i] = x[i + 1] - x[i];

        ll gcd = 0;
        for(int i = 0; i < n - 1; ++i)
            gcd = __gcd(gcd, x[i]);

        if(get_rem(x[n - 1], gcd) == get_rem(k, gcd)) cout << "YES\n";
        else cout << "NO\n";
    }
}