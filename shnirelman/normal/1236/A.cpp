#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int res = 0;
    while(b >= 1 && c >= 2) {
        b--;
        c -= 2;
        res += 3;
    }
    
    while(a >= 1 && b >= 2) {
        a--;
        b -= 2;
        res += 3;
    }
    
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    
    while(t--)
        solve();
}