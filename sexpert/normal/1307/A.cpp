#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int ans = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i] * i <= k) {
            k -= v[i] * i;
            ans += v[i];
            continue;
        }
        int x = k / i;
        ans += x;
        break;
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