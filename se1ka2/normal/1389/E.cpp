#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll m, d, w;
        cin >> m >> d >> w;
        if(min(m, d) == 1){
            cout << 0 << endl;
            continue;
        }
        w = w / gcd(w, d - 1);
        m = min(m, d);
        ll k = (m / w + 1) * (m % w);
        cout << (k * (m / w + 1) + (m - k) * (m / w) - m) / 2 << endl;
    }
}