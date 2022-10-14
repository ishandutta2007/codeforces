#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;
set<int> CUB;

void solve() {
    int n;
    cin >> n;
    for (auto x : CUB) {
        if (CUB.find(n-x) != CUB.end()) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 10000; i++) {
        CUB.insert(i * i * i);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}