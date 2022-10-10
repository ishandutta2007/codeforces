#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
        if(x % 2 == 0)
            cnt++;
    }
    if(cnt != (n + 1) / 2) {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] % 2 && i % 2 == 0)
            ans++;
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