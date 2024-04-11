#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll gcd(ll n, ll m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll s = 1;
        ll ans = 0;
        for(int i = 2; i <= n * 10; i++){
            ll u = s / gcd(s, i) * i;
            ans = (ans + (n / s - n / u) * i) % MOD;
            s = u;
            if(s > n) break;
        }
        cout << ans << endl;
    }
}