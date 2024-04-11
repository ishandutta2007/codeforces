#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int pv = -1;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'R') {
            ans = max(ans, i - pv);
            pv = i;
        }
    }
    ans = max(ans, (int)s.size() - pv);
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