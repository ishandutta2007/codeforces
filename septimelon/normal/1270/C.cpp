#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0LL;
    ll xo = 0LL;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        xo ^= a[i];
    }
    sum += xo;
    cout << "2\n" << xo << " " << sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}