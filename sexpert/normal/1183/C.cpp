#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll k, n, a, b;
    cin >> k >> n >> a >> b;
    if(k <= b*n) {
        cout << "-1\n";
        return;
    }
    ll lo = 0, hi = n;
    while(lo < hi) {
        ll mi = (lo + hi + 1)/2;
        if(a*mi + b*(n - mi) < k)
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
        solve();
}