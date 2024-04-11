#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m){
    if(n % m == 0) return m;
    else return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    vector<ll> p;
    bool prime[200002];
    fill(prime, prime + 200000, true);
    for(int i = 2; i < 200000; i++){
        if(prime[i]) p.push_back(i);
        for(int j = i; j < 200000; j += i) prime[j] = false;
    }
    for(int c = 0; c < t; c++){
        ll a, m;
        cin >> a >> m;
        ll g = gcd(a, m);
        a /= g;
        m /= g;
        ll r = m;
        vector<ll> v;
        for(ll x : p){
            if(r % x == 0){
                while(r % x == 0) r /= x;
                v.push_back(x);
            }
        }
        if(r != 1) v.push_back(r);
        ll k = v.size();
        ll ans = 0;
        for(int b = 0; b < (1 << k); b++){
            ll w = 0, z = 1;
            for(int j = 0; j < k; j++){
                if((b >> j) & 1){
                    w++;
                    z *= v[j];
                }
            }
            if(w % 2) ans -= m / z;
            else ans += m / z;
        }
        cout << ans << endl;
    }
}