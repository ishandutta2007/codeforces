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
    int n, m;
    cin >> n >> m;
    ll x[300005];
    for(int i = 0; i < n; i++) cin >> x[i];
    ll g = 0;
    for(int i = 1; i < n; i++) g = gcd(g, x[i] - x[i - 1]);
    ll p[300005];
    for(int i = 0; i < m; i++) cin >> p[i];
    for(int i = 0; i < m; i++) if(g % p[i] == 0){
        cout << "YES" << endl;
        cout << x[0] << " " << i + 1 << endl;
        return 0;
    }
    cout << "NO" << endl;
}