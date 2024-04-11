#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

ll x, y, n, g, k;
ll kx = 1, ky = 1;
vector <string> ans;

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> x >> y;
    g = gcd(x, y);

    x /= g;
    y /= g;

    while (true) {
        if (kx > x && ky > y)
            break;
        if (kx * y < ky * x) {
            ans.push_back("Vanya");
            kx++;
        } else if (kx * y > ky * x) {
            ans.push_back("Vova");
            ky++;
        } else {
            ans.push_back("Both");
            ans.push_back("Both");
            kx++;
            ky++;
        }
    }

    while (n --> 0) {
        cin >> k;
        cout << ans[(k - 1) % ans.size()] << "\n";
    }

    return 0;
}