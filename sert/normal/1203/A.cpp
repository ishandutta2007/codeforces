#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    a.push_back(a[0]);
    for (int i = 1; i <= n; i++) {
        int d = min((a[i] - a[i - 1] + n) % n, (a[i - 1] - a[i] + n) % n);
        if (d > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--) solve();
}