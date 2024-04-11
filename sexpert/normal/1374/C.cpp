#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    cin >> s;
    int ans = 0, cur = 0;
    for(auto c : s) {
        if(c == '(')
            cur++;
        else
            cur--;
        ans = max(ans, -cur);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}