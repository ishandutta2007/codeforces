#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cy[] = {0, 2, 3, 1};

void solve() {
    ll n, k = 0;
    cin >> n;
    n--;
    while(n >= (3LL << k)) {
        n -= (3LL << k);
        k += 2;
    }
    ll p = n / 3, t = n % 3;
    ll a = (1LL << k) + p, b = 0, c = 0;
    ll x = p, fc = 1;
    b += (1LL << (k + 1));
    while(x) {
        b += fc * cy[x % 4];
        fc *= 4;
        x /= 4;
    }
    c = a^b;
    cout << (t == 0 ? a : t == 1 ? b : c) << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}