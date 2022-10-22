#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000009;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int cm = 0, cb = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            ++cb;
        }
        if (a[i] <= a[i - 1]) {
            ++cm;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (cm >= n / 2 && cb >= n / 2) {
            break;
        }
        if (i > 0 && a[i] >= a[i - 1]) {
            --cb;
        }
        if (i > 0 && a[i] <= a[i - 1]) {
            --cm;
        }
        if (i < n - 1 && a[i] <= a[i + 1]) {
            --cb;
        }
        if (i < n - 1 && a[i] >= a[i + 1]) {
            --cm;
        }
        a[i] = 0 - a[i];
        if (i > 0 && a[i] >= a[i - 1]) {
            ++cb;
        }
        if (i > 0 && a[i] <= a[i - 1]) {
            ++cm;
        }
        if (i < n - 1 && a[i] <= a[i + 1]) {
            ++cb;
        }
        if (i < n - 1 && a[i] >= a[i + 1]) {
            ++cm;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
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