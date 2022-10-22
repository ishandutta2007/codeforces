#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int nc[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + a[i]) % 2 != 0) {
            ++nc[i % 2];
        }
    }
    if (nc[0] == nc[1]) {
        cout << nc[0] << "\n";
    } else {
        cout << "-1\n";
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