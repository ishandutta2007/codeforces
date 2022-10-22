#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void printv(vector<ll> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    int minpe = b[0];
    int zapas = 0;
    int curfl = b[0];
    for (int i = 1; i < n; ++i) {
        if (curfl + b[i] < a[i]) {
            cout << "NO\n";
            return;
        } else if (curfl <= a[i]) {
            curfl = b[i] - (a[i] - curfl);
            minpe = min(minpe, curfl);
        } else {
            zapas += min(minpe, curfl - a[i]);
            minpe -= min(minpe, curfl - a[i]);
            minpe = min(minpe, b[i]);
            curfl = b[i];
        }
    }
    if (zapas + curfl < a[0]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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