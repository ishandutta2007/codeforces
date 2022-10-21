#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c, l;

ll solve(ll x) {
    if(x < 0) return 0;
    return (x + 1) * (x + 2) / 2;
}

int main() {
    cin >> a >> b >> c >> l;
    ll res = 1LL * (l + 1) * (l + 2) * (l + 3) / 6;
    for(int i = 0; i <= l; i++) {
        res -= solve(min(a + i - b - c, l - i));
        res -= solve(min(b + i - a - c, l - i));
        res -= solve(min(c + i - a - b, l - i));
    }
    cout << res << endl;


}