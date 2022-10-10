#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    for(int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for(auto &c : s)
            if(c == '2') c = '1';
        cout << s << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}