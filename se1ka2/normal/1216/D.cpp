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
    ll lar = 0;
    ll a[200005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        lar = max(lar, a[i]);
    }
    ll z = 0;
    for(int i = 0; i < n; i++) z = gcd(z, lar - a[i]);
    if(z == 0){
        cout << "0 0" << endl;
        return 0;
    }
    ll y = 0;
    for(int i = 0; i < n; i++) y += (lar - a[i]) / z;
    cout << y << " " << z << endl;
}