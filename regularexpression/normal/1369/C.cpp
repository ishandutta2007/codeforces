#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    vector<int> w;
    int pos = n - 1;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if (x == 1) ans += a[pos--] * 2; else w.pb(x - 1);
    }
    for (auto x : w) ans += a[pos--];
    sort(all(w));
    for (auto x : w) {
        pos -= x;
        ans += a[pos + 1];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}