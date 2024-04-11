#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    v[n - 1] += k;
    for(auto &x : v) {
        int d = min(x, k);
        x -= d;
        k -= d;
    }
    for(auto &x : v)
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