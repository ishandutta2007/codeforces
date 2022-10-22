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
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        ll g = 0;
        for(int i = 1; i < n; i++) g = gcd(g, a[i] - a[i - 1]);
        if(gcd(g, k - a[0]) % g == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}