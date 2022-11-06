#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;

        if(x < y) swap(x, y);

        ll ans = min(2*a, b) * y;
        ans += (x-y) * a;

        cout << ans << '\n';
    }
}