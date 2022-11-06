#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector <vector<ll>> a(n + 2, vector<ll>(m + 2, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector <vector<ll>> b(n + 2, vector<ll>(m + 2, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (a[i][j] > b[i][j]) {
                swap(a[i][j], b[i][j]);
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (a[i][j] <= a[i - 1][j] || a[i][j] <= a[i][j - 1]) {
                swap(a[i][j], b[i][j]);
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (a[i][j] <= a[i - 1][j] || a[i][j] <= a[i][j - 1] || b[i][j] <= b[i - 1][j] || b[i][j] <= b[i][j - 1]) {
                cout << "Impossible";
                return 0;
            }
        }
    }
    cout << "Possible";
    return 0;
}