#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
        if(p == 0) {
            cout << (x == 0 ? "0\n" : "-1\n");
            continue;
        }
        if(p == q) {
            cout << (x == y ? "0\n" : "-1\n");
            continue;
        }
        ll owo = max(0LL, p*y - q*x);
        ll mina = (owo + q - p - 1) / (q - p);
        // p divides x + a
        ll a = mina;
        if((x + a) % p)
            a += (p - (x + a) % p);
        ll b = (x + a)/p * q - y - a;
        cout << a + b << '\n';
    }
}