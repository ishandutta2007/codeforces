#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

void f() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n + 7);
    for (int i = 1; i <= n; i++) cin >> A[i];
    vector<int> c;
    for (int i = 1; i <= n - 1; i++) {
        if (A[i] > A[i + 1]) {
            c.pb(i);
        }
    }
    if (c.empty()) {
        cout << "0\n";
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] > x) {
            swap(x, A[i]);
            ans++;
            bool ok = true;
            for (int ii = 1; ii < n; ii++) {
                if (A[ii] > A[ii+1]) ok = false;
            }
            if (ok) {
                cout << ans << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        f();
    }

}