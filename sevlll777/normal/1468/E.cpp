#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

void sol() {
    vector<int> a(4);
    for (int &el : a) {
        cin >> el;
    }
    sort(all(a));
    cout << a[0] * a[2] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}