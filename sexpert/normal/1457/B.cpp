#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = n + 2;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(int c = 1; c <= 100; c++) {
        int pv = INT_MIN, cur = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == c)
                continue;
            if(i >= pv + k) {
                cur++;
                pv = i;
            }
        }
        ans = min(ans, cur);
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