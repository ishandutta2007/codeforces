#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = n;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ans = max({ans, 2*(i + 1), 2*(n - i)});
        }
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