#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s >> s;
    int sum = 0, n = s.size(), ans = 0;
    for(int i = 0; i + 1 < n; i++)
        if(s[i] != s[i + 1])
            ans++;
    if(s[0] == '0' && ans)
        ans--;
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