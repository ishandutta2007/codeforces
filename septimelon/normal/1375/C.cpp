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
    
    stack<int> deg;
    for (int i = 1; i < n; ++i) {
        while (!deg.empty() && deg.top() < a[i]) {
            deg.pop();
        }
        if (!deg.empty() || a[0] > a[i]) {
            deg.push(a[i]);
        }
    }
    
    if (!deg.empty()) {
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