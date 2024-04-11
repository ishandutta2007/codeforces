#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 4;
typedef long long ll;
typedef long double ld;
const ll md = 1e9 + 9;
const ll p1 = 997;
const ll p2 = 2011;

ll n, k, ans;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n >> k;
    k--;
    n--;
if (n ==0){cout << 0;return 0;}
    if (k * (k + 1) < n * 2) {
        cout << -1;
        return 0;
    }

    ll l = 0;
    ll r = k + 1;
    ll m;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (k * (k + 1) / 2 - m * (m - 1) / 2 >= n)
            l = m;
        else
            r = m;
    }

    ans = k - l + 1;
    /*if (k * (k + 1) - m * (m - 1) != n * 2)
        ans++;*/
    cout << ans;

    return 0;
}