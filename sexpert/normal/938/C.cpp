#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    ll x;
    cin >> x;

    if(x == 0) {
        cout << "1 1\n";
        return;
    }
    if(x == 1 || ((x % 2) == 0 && (x % 4) == 2)) {
        cout << "-1\n";
        return;
    }
    for(ll d = 1; d * d < x; d++) {
        if(x % d)
            continue;
        ll d2 = x / d;
        if(d % 2 != d2 % 2)
            continue;
        ll n = (d + d2)/2;
        ll k = (d2 - d)/2;
        ll lo = 1, hi = n;
        while(lo < hi) {
            ll mi = (lo + hi + 1)/2;
            if(n/mi >= k)
                lo = mi;
            else
                hi = mi - 1;
        }
        if(n / lo == k) {
            cout << n << " " << lo << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}