#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;
const ll p = 31;

ll a, b, q, ans;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> a >> b;

    if (a == b) {
        cout << "infinity\n";
        return 0;
    }

    if (a < b) {
        cout << 0;
        return 0;
    }

    a -= b;
    q = sqrt(a);

    for (ll d = 1; d * d <= a; d++) 
        if (a % d == 0) {
            if (d > b) ans++;
            if (a / d > b && a / d != d) ans++;
        }

    cout << ans;

    //return 0;
}