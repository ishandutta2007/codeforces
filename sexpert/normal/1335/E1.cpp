#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    vector<int> cnt(205);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
        cnt[x]++;
    }
    int ans = *max_element(cnt.begin(), cnt.end());
    for(int val = 1; val <= 200; val++) {
        int l = 0, r = n - 1;
        vector<int> tcnt = cnt;
        for(int cn = 1; 2 * cn <= cnt[val]; cn++) {
            do {
                tcnt[v[l++]]--;
            } while(v[l - 1] != val);
            do {
                tcnt[v[r--]]--;
            } while(v[r + 1] != val);
            for(int v = 1; v <= 200; v++)
                ans = max(ans, 2 * cn + tcnt[v]);
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