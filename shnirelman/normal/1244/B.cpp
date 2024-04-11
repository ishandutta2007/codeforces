#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int a = 0, b = 0;
    int l = n, r = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            l = min(l, i);
            r = max(r, i);
        }
    }
    
    if(l == n) {
        cout << n << endl;
        return;
    } else {
        int ans = max((n - l) * 2, (r + 1) * 2);
        cout << ans << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t--)  
        solve();
}