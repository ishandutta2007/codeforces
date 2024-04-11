#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll a, b, k;
        cin >> a >> b >> k;
        if(a == b) {
            cout << "OBEY\n";
            continue;
        }
        ll d = __gcd(a, b);
        a /= d;
        b /= d;
        if(a > b)
            swap(a, b);
        if((b + a - 2)/a < k)
            cout << "OBEY\n";
        else
            cout << "REBEL\n";
    }
}