#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int sum = 0;
    int lst = n;
    int rst = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] % x != 0) {
            rst = i;
            if (lst == n) {
                lst = i;
            }
        }
    }
    //cout << sum << " " << lst << " " << rst << " ";
    if (sum % x != 0) {
        cout << n << endl;
    } else {
        cout << max(n - lst - 1, rst) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    return 0;
}