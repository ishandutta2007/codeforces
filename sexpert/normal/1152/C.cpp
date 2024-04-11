#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll a, b;
ll s(ll x) {
    if(a % x == 0)
        return 0;
    return x - a%x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
    if(a == b) {
        cout << "0\n";
        return 0;
    }
    if(a > b)
        swap(a, b);
    ll g = b - a;
    ll ans = 1e18, cur = 1e18;
    for(ll d = 1; d*d <= g; d++) {
        if(g % d)
            continue;
        //cout << g << " " << d << endl;
        ll k = s(d);
        //cout << k << endl;
        ll res = (a + k)*(b + k)/d;
        if(res < cur || (res == cur && ans < k)) {
            cur = res;
            ans = k;
        }
        ll w = g / d;
        k = s(w);
        //cout << k << endl;
        res = (a + k)*(b + k)/w;
        if(res < cur || (res == cur && ans < k)) {
            cur = res;
            ans = k;
        }
    }
    cout << ans << '\n';
}