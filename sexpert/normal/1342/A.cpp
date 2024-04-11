#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if(b > a + a)
            cout << a * (x + y) << '\n';
        else
            cout << b * (min(x, y)) + a * (x + y - 2 * min(x, y)) << '\n';
    }
}