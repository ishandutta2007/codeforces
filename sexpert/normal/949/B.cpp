#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll find(ll i, ll k) {
    if(i == 0)
        return 0;
    ll ans = 1;
    for(ll d = k - 1; d >= 0; d--) {
        if(i % (1LL << d)) {
            ans += (1LL << (k - 1 - d));
            continue;
        }
        return ans + (i >> (d + 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    int q;
    cin >> n >> q;
    ll k = 0;
    while(n > (1LL << k))
        k++;
    ll shif = (1LL << k) - n;
    while(q--) {
        ll p;
        cin >> p;
        if(p + shif <= n) {
            cout << n - find(n - (p + shif), k) << '\n';
            continue;
        }
        ll steps = n - p;
        ll owo = shif - steps;
        cout << n - find((n + steps) - owo, k) << '\n';
    }
}