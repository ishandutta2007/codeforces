#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, vector<int>> pos;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }

    ll ans = 0;
    for(auto [x, v] : pos) {
        int m = v.size();
        ll tot_sum = 0;
        for(int i = 0; i < m; i++)
            tot_sum += (n - v[i]);

        for(int i = 0; i < m; i++) {
            tot_sum -= (n - v[i]);
            ans += tot_sum * (v[i] + 1);
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