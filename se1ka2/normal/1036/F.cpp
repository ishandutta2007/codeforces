#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll cpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n & 1) res *= r;
        r = r * r;
        n >>= 1;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    ll p[18] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
    ll d[63]{0};
    for(int i = 2; i < 63; i++){
        int l = i;
        for(int j = 0; j < 18; j++){
            if(l % p[j] == 0){
                l /= p[j];
                d[i]++;
            }
        }
        if(l != 1) d[i] = -1;
    }
    for(int c = 0; c < t; c++){
        ll n;
        cin >> n;
        ll ans = n - 1;
        for(ll i = 2; i < 63; i++){
            if(d[i] == -1) continue;
            ll p = pow(n + 1, 1.0 / i);
            if(cpow(p, i) >= n + 1) p--;
            if(d[i] % 2) ans -= p - 1;
            else ans += p - 1;
        }
        cout << ans << endl;
    }
}