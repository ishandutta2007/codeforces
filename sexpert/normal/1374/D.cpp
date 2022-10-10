#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x % k == 0)
            continue;
        cnt[k - x % k]++;
    }
    ll ans = -1;
    for(auto p : cnt) {
        int rem = p.first, quo = p.second;
        ans = max(ans, rem + (ll)k * (quo - 1));
    }
    cout << ans + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}