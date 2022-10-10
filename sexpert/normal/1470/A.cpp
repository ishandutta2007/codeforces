#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> guys(n);
    ll ans = 0;
    vector<ll> cost(m + 1);
    for(auto &x : guys)
        cin >> x;
    sort(guys.begin(), guys.end());
    int l = 0, r = n - 1;
    for(int i = 1; i <= m; i++) {
        ll c;
        cin >> c;
        if(l <= r) {
            r--;
            ans += c;
        }
        while(l <= r && guys[l] == i) {
            l++;
            ans += c;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}