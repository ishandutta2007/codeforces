#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    vector<ll> ans;
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == n - 1 || (v[i] - v[i - 1]) * (v[i] - v[i + 1]) > 0)
            ans.push_back(v[i]);
    }
    cout << ans.size() << '\n';
    for(auto &x : ans)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}