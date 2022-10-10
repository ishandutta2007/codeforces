#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(2*n + 1), b(2*n + 1), c(2*n + 1);
    ll as = 0, bs = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        as += a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        bs += b[i];
    }
    for(int i = n + 1; i <= 2*n; i++) {
        a[i] = a[i - n];
        b[i] = b[i - n];
    }
    b[0] = b[n];
    if(bs < as) {
        cout << "NO\n";
        return;
    }
    for(int i = 1; i <= 2*n; i++)
        c[i] = b[i] - a[i];
    ll cur = 0;
    for(int i = 2*n; i >= 1; i--) {
        cur = min(cur + c[i], c[i]);
        if(i <= n && b[i - 1] + cur < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}