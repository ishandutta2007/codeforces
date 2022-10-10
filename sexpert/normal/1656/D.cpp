#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    ll a = 1, b = 1, m = 2*n;
    while(m % 2 == 0) {
        m /= 2;
        a *= 2;
    }
    b = m;
    if(b == 1) {
        cout << "-1\n";
        return;
    }
    if(b >= a)
        cout << a << '\n';
    else
        cout << b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}