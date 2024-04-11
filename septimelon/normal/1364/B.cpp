#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    int lst = n;
    int rst = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            b.push_back(a[i]);
        }
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
            b.push_back(a[i]);
        }
    }
    if (n > 1) {
        b.push_back(a.back());
    }
    cout<< b.size() << "\n";
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";
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