#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[0] << '\n';
    } else {
        cout << "1 " << n - 1 << '\n';
        for (int i = 0; i < n - 1; i++) {
            int x = n * (n - a[i]) - n + a[i];
            a[i] -= x;
            cout << -x << " ";
        }
        cout << '\n' << n << " " << n << '\n' << -a[n - 1] << '\n';
        a[n - 1] = 0;
        cout << "1 " << n << '\n';
        for (int i = 0; i < n; i++)
            cout << -a[i] << " ";
        cout << '\n';
    }
    return 0;
}