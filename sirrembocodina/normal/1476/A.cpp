#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int x = (n + k - 1) / k;
        k *= x;
        cout << (k + n - 1) / n << endl;
    }
}