#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    
    int x = (a + c - 1) / c, y = (b + d - 1) / d;
    
    if(x + y <= k) 
        cout << x << ' ' <<  y << endl;
    else
        cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    
    while(t--)  
        solve();
}