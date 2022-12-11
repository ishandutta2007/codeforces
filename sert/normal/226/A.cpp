#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
ll md;
ll step(ll a, ll st) {
    if (st == 0) return 1;
    if (st % 2)
        return (a * step(a, st - 1)) % md;
    ll q = step(a, st / 2);
    return (q * q) % md;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ll n;
    cin >> n >> md;
    cout << (step(3, n) + md - 1) % md;


    return 0;
}