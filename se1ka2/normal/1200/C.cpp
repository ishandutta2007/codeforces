#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    ll n, m, q;
    cin >> n >> m >> q;
    ll d = gcd(n, m);
    for(int c = 0; c < q; c++){
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        if(sx == 1) sy = (sy - 1) / (n / d);
        else sy = (sy - 1) / (m / d);
        if(ex == 1) ey = (ey - 1) / (n / d);
        else ey = (ey - 1) / (m / d);
        if(sy == ey) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}