#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b) {
    return a*b/__gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    ll res = 1;
    while(n--) {
        ll y;
        cin >> y;
        res = __gcd(x, lcm(res, y));
    }
    cout << (res == x ? "Yes" : "No") << '\n';
}