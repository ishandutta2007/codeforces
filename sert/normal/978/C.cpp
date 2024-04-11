//made by Sert
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i] + (i > 0 ? b[i - 1] : 0);
    }
    while (k--) {
        ll x;
        cin >> x;
        int ind = lower_bound(b.begin(), b.end(), x) - b.begin();
        cout << ind + 1 << " " << a[ind] - (b[ind] - x) << "\n";
    }
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    //solve();
#endif
    solve();
    return 0;
}