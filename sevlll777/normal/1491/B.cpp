#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n - 1; i++) {
        if (abs(A[i] - A[i + 1]) >= 2) {
            cout << "0\n";
            return;
        }
    }
    sort(all(A));
    if (A[0] == A[n - 1]) {
        cout << v + min(u, v) << '\n';
    } else {
        cout << min(u, v) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}