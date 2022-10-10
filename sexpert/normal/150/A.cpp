#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll q;
    cin >> q;
    if(q == 1) {
        cout << "1\n0\n";
        return 0;
    }
    ll a = -1, b = -1;
    for(ll d = 2; d * d <= q; d++) {
        if(q % d)
            continue;
        a = d;
        b = q/d;
        break;
    }
    if(a == -1) {
        cout << "1\n0\n";
        return 0;
    }
    for(ll d = 2; d * d <= b; d++) {
        if(b % d)
            continue;
        cout << "1\n" << a * d << '\n';
        return 0;
    }
    cout << "2\n";
}