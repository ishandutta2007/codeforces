#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

ll d(ll n){
    ll res = 0;
    while(n){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(gcd(n, d(n)) > 1) cout << n << endl;
        else if(gcd(n + 1, d(n + 1)) > 1) cout << n + 1 << endl;
        else cout << n + 2 << endl;
    }
}