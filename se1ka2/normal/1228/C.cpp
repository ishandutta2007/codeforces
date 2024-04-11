#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int p[100000];

ll modpow(ll x, ll n){
    ll res = 1;
    ll mul = x;
    while(n){
        if(n % 2) res = res * mul % MOD;
        mul = mul * mul % MOD;
        n /= 2;
    }
    return res;
}

int main()
{
    vector<ll> v;
    for(ll i = 2; i < 100000; i++){
        if(p[i] == 0){
            v.push_back(i);
            for(int j = 0; j < 100000; j += i) p[j] = 1;
        }
    }
    ll x, n;
    cin >> x >> n;
    vector<ll> w;
    for(ll q : v){
        if(x % q == 0) w.push_back(q);
        while(x % q == 0) x /= q;
    }
    if(x != 1) w.push_back(x);
    ll ans = 1;
    for(ll q : w){
        ll b = q;
        ans = (ans * modpow(q, n / q)) % MOD;
        while(n / b >= q){
            b *= q;
            ans = (ans * modpow(q, n / b)) % MOD;
        }
    }
    cout << ans << endl;
}