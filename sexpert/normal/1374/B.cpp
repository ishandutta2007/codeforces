#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    
    int ans = 0;
    while(n % 6 == 0) {
        ans++;
        n /= 6;
    }
    while(n % 3 == 0) {
        ans += 2;
        n /= 3;
    }
    if(n > 1)
        cout << "-1\n";
    else
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