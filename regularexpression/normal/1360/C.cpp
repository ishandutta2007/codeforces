#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define ll long long
#define ld long double
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> o, e;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a & 1) o.pb(a); else e.pb(a);
    }
    if (sz(o) & 1) {
        bool ok = 0;
        for (auto x : o) {
            for (auto y : e) {
                if (abs(x - y) == 1) ok = 1;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    } else cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}