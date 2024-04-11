#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, k;
    cin >> n >> q >> k;

    vector<int> a(n);
    for(auto &x : a)
        cin >> x;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << 2 * k - 2 * (r - l + 1) - (a[l] - 1) - (k - a[r]) << '\n';
    }
}