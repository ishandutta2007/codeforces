#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

void solve() {
    int ans = 0, n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int pm = -INF;
    for(auto x : v) {
        ans = max(ans, pm - x);
        pm = max(pm, x);
    }
    if(ans == 0)
        cout << "0\n";
    else
        cout << __lg(ans) + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}