#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;

int f(int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    if (2 * x >= y) {
        return 0;
    }
    return 1 + f(2 * x, y);
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += f(A[i], A[i + 1]);
    }
    cout << ans << '\n';
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