#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x, d;
    cin >> x >> d;
    ll cur = 30;
    ll kk = 1;
    vector<ll> ans;
    while (x > 0) {
        while (x < (1ll << cur) - 1) cur--;
        x -= (1ll << cur) - 1;
        for (int i = 0; i < cur; i++) ans.push_back(kk);
        kk += d + 1;
    }
    cout << ans.size() << "\n";
    for (ll x: ans) cout << x << " ";
    cout << "\n";
}

int main() {
    solve();
    return 0;

}