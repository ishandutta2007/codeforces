#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define int long long
#define ll long long

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cout << ((i + 1) * 4 <= n * 3 ? 9 : 8);
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}