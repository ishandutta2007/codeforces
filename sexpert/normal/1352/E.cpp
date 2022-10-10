#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), good(n + 1);
    for(auto &x : v)
        cin >> x;
    for(int l = 0; l + 1 < n; l++) {
        int r = l, cur = v[l];
        while(r + 1 < n && cur + v[r + 1] <= n) {
            r++;
            cur += v[r];
            good[cur] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += good[v[i]];
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