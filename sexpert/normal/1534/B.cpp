#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v = {0};
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.push_back(0);
    ll ans = 0;
    for(int i = 1; i < v.size(); i++)
        ans += abs(v[i] - v[i - 1]);
    for(int i = 1; i <= n; i++)
        ans -= max(0, v[i] - max(v[i - 1], v[i + 1]));
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