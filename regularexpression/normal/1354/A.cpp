#include<bits/stdc++.h>
using namespace std;

#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a = max(0LL, a - b);
    if (a == 0) cout << b << '\n'; else {
        if (d >= c) cout << "-1\n"; else cout << b + c * ((a + c - d - 1) / (c - d)) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}