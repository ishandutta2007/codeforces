#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, d, e;


int main() {
    cin >> n >> d >> e;

    ll res = n;
    for(ll i = 0; i * e * 5 <= n; i++) {
        ll rem = n - i * e * 5;
        res = min(res, rem - rem / d * d);
    }
    cout << res << "\n";
}