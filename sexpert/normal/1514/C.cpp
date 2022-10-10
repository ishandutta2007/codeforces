#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    ll res = 1;
    set<ll> uwu;
    for(ll x = 1; x <= n; x++) {
        if(__gcd(x, n) > 1)
            continue;
        uwu.insert(x);
        res = (res * x) % n;
    }
    if(res != 1)
        uwu.erase(res);
    cout << uwu.size() << '\n';
    for(auto &x : uwu)
        cout << x << " ";
    cout << '\n';
}