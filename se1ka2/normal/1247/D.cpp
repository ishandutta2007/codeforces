#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

ll p[1002];

ll power(ll x, ll n){
    ll res = 1;
    for(int i = 0; i < n; i++){
        res *= x;
        if(res > 1000000) return 0;
    }
    return res;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v;
    for(int i = 2; i <= 500; i++){
        if(p[i] == 0){
            v.push_back(i);
            for(int j = i; j <= 500; j += i) p[j] = 1;
        }
    }
    ll a[100002];
    map<ll, ll> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(ll q : v){
            ll r = power(q, k);
            if(r == 0) continue;
            while(a[i] % r == 0){
                a[i] /= r;
            }
        }
        mp[a[i]]++;
    }
    ll ans = mp[1] * (mp[1] - 1) / 2;
    for(ll i = 2; i <= 100000; i++){
        if(mp[i] == 0) continue;
        ll l = i;
        ll m = 1;
        for(ll q : v){
            int d = 0;
            while(l % q == 0){
                l /= q;
                d++;
            }
            if(d != 0){
                m *= power(q, k - d);
                if(m > 100000) m = 0;
            }
        }
        m *= power(l, k - 1);
        if(m != 0){
            if(m > i) ans += mp[i] * mp[m];
            if(m == i) ans += mp[i] * (mp[i] - 1) / 2;
        }
    }
    cout << ans << endl;
}