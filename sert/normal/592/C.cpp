#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 800;
const ll md = 1e9 + 7;

ll gcd(ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

void ans(ll ch, ll zn) {
    ll g = gcd(ch, zn);
    cout << ch / g << "/" << zn / g;
    exit(0);
}

ll x, a, b;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> x >> a >> b;
    ll g = gcd(a, b);
    if (a > b) swap(a, b);

    if (a / g > x / b) {
        ans(min(x, a - 1), x);
    }
    ll nok = a / g * b;

    ll n = (a - 1) + (x / nok - 1) * a + min(a, (x % nok) + 1);

    ans(n, x);

    return 0;
}