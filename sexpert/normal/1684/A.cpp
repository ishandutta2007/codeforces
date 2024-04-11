#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s.size() == 2) {
            cout << s[1] << '\n';
            continue;
        }
        int ans = 10;
        for(auto c : s)
            ans = min(ans, c - '0');
        cout << ans << '\n';
    }
}