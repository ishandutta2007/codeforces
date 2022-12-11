#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const ll md = 1e9 + 7;

ll a[N];
ll n, m, t, k;
string s;

ll step(ll a, ll st) {
    if (st == 0) return 1;
    if (st % 2) return (a * step(a, st - 1)) % md;
    ll q = step(a, st / 2);
    return (q * q) % md; 
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;

    cout << (step(3, 3 * n) - step(7, n) + md * md) % md;

    //while (true);

    return 0;
}