#include<bits/stdc++.h>
using namespace std;

#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    if (r + g + b - max({r, g, b}) >= max({r, g, b}) - 1) {
        cout << "Yes\n";
    } else cout << "No\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}