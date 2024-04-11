#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 1; j < n; ++j) {
        int mov = a[j] * j;
        if (mov > d) {
            a[0] += d / j;
            break;
        }
        d -= mov;
        a[0] += a[j];
    }
    cout << a[0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}