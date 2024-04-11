#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int ans = 0, sz = 1;
    v.push_back(0);
    for(int i = 1; i <= n; i++) {
        if(v[i] == v[i - 1])
            sz++;
        else {
            ans = max(ans, sz);
            sz = 1;
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