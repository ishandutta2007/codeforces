#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m){
    if(m == 0) return n;
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int n;
    cin >> n;
    ll g = 0;
    for(int i = 0; i < n; i++){
        ll a;
        scanf("%lld", &a);
        g = gcd(g, a);
    }
    ll ans = 1;
    for(int i = 2; i <= 1000000; i++){
        if(g % i == 0){
            ll l = 1;
            while(g % i == 0){
                g /= i;
                l++;
            }
            ans *= l;
        }
    }
    if(g != 1) ans *= 2;
    cout << ans << endl;
}