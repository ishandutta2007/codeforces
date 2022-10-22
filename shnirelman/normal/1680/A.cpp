#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    if(min(r1, r2) >= max(l1, l2))
        cout << max(l1, l2) << endl;
    else
        cout << l1 + l2 << endl;
}

int main() {

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}