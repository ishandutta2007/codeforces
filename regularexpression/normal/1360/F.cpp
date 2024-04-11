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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &e : a) cin >> e;
    for (int i = 0; i < m; i++) {
        char kek = a[0][i];
        for (int c = 0; c < 26; c++) {
            a[0][i] = 'a' + c;
            bool ok = 1;
            for (int j = 0; j < n; j++) {
                int cn = 0;
                for (int k = 0; k < m; k++) {
                    if (a[0][k] != a[j][k]) {
                        cn++;
                        if (cn > 1) break;
                    }
                }
                if (cn > 1) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << a[0] << '\n';
                return;
            }
        }
        a[0][i] = kek;
    }
    cout << "-1\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}