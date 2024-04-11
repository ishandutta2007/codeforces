#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int l, r;
    cin >> l >> r;
    if(2 * l > r) {
        cout << "-1 -1\n";
        return;
    }
    cout << l << " " << 2*l << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}