#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000009;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    
    int ans = 0;
    vector<bool> usd(n + 1, false);
    for (int i = 0; i < n; ++i) {
        usd[t[i]] = true;
    }
    for (int i = 0; i <= n; ++i) {
        if (!usd[i]) {
            ++ans;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}