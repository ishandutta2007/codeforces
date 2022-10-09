#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "1 1" << endl;
        cout << -a[0] << endl;
        cout << "1 1" << endl;
        cout << 0 << endl;
        cout << "1 1" << endl;
        cout << 0 << endl;
        return 0;
    }
    cout << "1 " << n << endl;
    for (int i = 0; i <  n - 1; i++) {
        cout << -a[i] * n << " ";
        a[i] -= a[i] * n;
    }
    cout << 0 << endl;
    cout << "1 " << n - 1 << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << -a[i] << " ";
    }
    cout << endl;
    cout << n << " " << n << endl;
    cout << -a[n - 1] << endl;
}