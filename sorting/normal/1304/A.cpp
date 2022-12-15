#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    y -= x;
    a += b;
    
    if(y % a == 0)
        cout << y / a << "\n";
    else
        cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--)
        solve();
}