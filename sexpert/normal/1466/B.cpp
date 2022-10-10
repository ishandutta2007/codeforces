#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    sort(v.rbegin(), v.rend());
    int cur = INF, ans = 0;
    for(auto &x : v) {
        if(x + 1 < cur) {
            cur = x + 1;
            ans++;
            continue;
        }
        if(x < cur) {
            cur = x;
            ans++;
            continue;
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